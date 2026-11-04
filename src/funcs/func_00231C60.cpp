typedef int qword_00231C60 __attribute__((mode(TI)));

extern void* D_00392068;

extern "C" float sqrtf(float);

class Iter_00231C60 {
public:
    void* m_node;
    int m_index;
    Iter_00231C60() : m_index(0) {}
    virtual ~Iter_00231C60() {}
    virtual void Run();
};

struct Vec_00231C60 {
    union {
        qword_00231C60 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_00231C60() {}
    Vec_00231C60(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct MsgDesc_00231C60 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Obj_00231C60 {
    char pad[0x50];
    Vec_00231C60 m_pos;
};

static inline Vec_00231C60 Diff_00231C60(Obj_00231C60* a, Obj_00231C60* b)
{
    Vec_00231C60 r(a->m_pos.f.x - b->m_pos.f.x, a->m_pos.f.y - b->m_pos.f.y, a->m_pos.f.z - b->m_pos.f.z,
                   a->m_pos.f.w - b->m_pos.f.w);
    return r;
}

struct Player_00231C60 {
    char pad[0x18];
    Obj_00231C60* m_obj;
};

struct Msg_00231C60 {
    void* m_Data;
    unsigned char m_Id;
    char pad5[3];
    unsigned short m_Length;
    char padA[6];
    void* m_client;
    int m_conn;
};

extern "C" Player_00231C60* func_002A5248(void* net, int conn);
extern "C" Player_00231C60* func_002A53F8(void* net, Iter_00231C60* it, int a);
extern "C" Player_00231C60* func_002A5490(void* net, Iter_00231C60* it, int a);
extern "C" bool func_002B1FE8(Player_00231C60* p);
extern "C" MsgDesc_00231C60* func_001FA800(MsgDesc_00231C60* desc);
extern "C" int func_002B3080(Player_00231C60* player);
extern "C" void func_001FF970(void* client, int conn, MsgDesc_00231C60* desc);

int func_00231C60(Msg_00231C60* msg)
{
    Iter_00231C60 it;
    void* net = D_00392068;
    Player_00231C60* sender = func_002A5248(net, msg->m_conn);
    if (!sender)
        return 3;
    Obj_00231C60* src = sender->m_obj;
    if (!src)
        return 3;
    for (Player_00231C60* p = func_002A53F8(net, &it, 1); p; p = func_002A5490(net, &it, 1)) {
        bool send = false;
        if (p != sender) {
            if (func_002B1FE8(p)) {
                send = true;
            } else {
                Obj_00231C60* o = p->m_obj;
                if (o) {
                    Vec_00231C60 d = Diff_00231C60(o, src);
                    if (sqrtf(d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z) < 1800.0f)
                        send = true;
                }
            }
        }
        if (send) {
            MsgDesc_00231C60 desc;
            func_001FA800(&desc);
            desc.m_Data = msg->m_Data;
            desc.m_Length = msg->m_Length;
            desc.m_Id = msg->m_Id;
            func_001FF970(msg->m_client, func_002B3080(p), &desc);
        }
    }
    return 1;
}
