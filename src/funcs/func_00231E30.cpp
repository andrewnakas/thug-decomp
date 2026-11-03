extern void* D_00392068;

class Iter_00231E30 {
public:
    void* m_node;
    int m_index;
    Iter_00231E30() : m_index(0) {}
    virtual ~Iter_00231E30() {}
    virtual void Run();
};

struct MsgDesc_00231E30 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Pos_00231E30 {
    int m_0;
    int m_4;
    int m_8;
    signed char m_C;
};

struct Msg_00231E30 {
    Pos_00231E30* m_Data;
    unsigned char m_Id;
    char pad5[3];
    unsigned short m_Length;
    char padA[6];
    void* m_client;
    int m_conn;
};

extern "C" void* func_002A5248(void* net, int conn);
extern "C" void* func_002A53F8(void* net, Iter_00231E30* it, int a);
extern "C" void* func_002A5490(void* net, Iter_00231E30* it, int a);
extern "C" void func_001FA800(MsgDesc_00231E30* desc);
extern "C" int func_002B3080(void* player);
extern "C" void func_001FF970(void* client, int conn, MsgDesc_00231E30* desc);
extern "C" void func_002A7EE8(void* net, int a, int b, int c);

int func_00231E30(Msg_00231E30* msg)
{
    Iter_00231E30 it;
    void* net = D_00392068;
    void* sender = func_002A5248(net, msg->m_conn);
    if (!sender)
        return 3;
    for (void* p = func_002A53F8(net, &it, 1); p; p = func_002A5490(net, &it, 1)) {
        MsgDesc_00231E30 desc;
        func_001FA800(&desc);
        if (p != sender) {
            desc.m_Data = msg->m_Data;
            desc.m_Length = msg->m_Length;
            desc.m_Id = msg->m_Id;
            desc.m_Priority = 2;
            desc.m_Queue = 8;
            func_001FF970(msg->m_client, func_002B3080(p), &desc);
        }
    }
    if (msg->m_Id == 0x49) {
        Pos_00231E30* d = msg->m_Data;
        if (d->m_C)
            func_002A7EE8(net, d->m_8, d->m_4, d->m_0);
    }
    return 1;
}
