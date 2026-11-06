/* sym: __12Msg_0018C230 = 0x001FA800 */

struct Data_0018C230 {
    int m_value;
    unsigned char m_id;
    unsigned char m_flag;
};

class Msg_0018C230 {
public:
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    char pad8[0x18];
    Msg_0018C230();
};

struct Owner_0018C230 {
    char pad0[0x18];
    int m_id;
    int GetId() { return m_id; }
};

extern void* D_00392068;
extern "C" void* func_002A52F0(void* net, int id);
extern "C" int func_002B1FC8(void* player);
extern "C" int func_002B30A0(void* player);
extern "C" void* func_002A39E0(void* net, int conn);
extern "C" void func_00200C00(void* conn, Msg_0018C230* msg);
extern "C" void func_0013EB18(void* scene, int a, int b);

class Comp_0018C230 {
public:
    char pad0[0xC];
    Owner_0018C230* m_owner;
    char pad10[0x250];
    void* m_scene;

    bool SetAnim(int anim, int flag, int send);
};

bool Comp_0018C230::SetAnim(int anim, int flag, int send)
{
    if (send) {
        void* net = D_00392068;
        void* player = func_002A52F0(net, (unsigned short)m_owner->m_id);
        if (player && func_002B1FC8(player)) {
            Data_0018C230 data;
            Msg_0018C230 msg;
            void* conn = func_002A39E0(net, func_002B30A0(player));
            data.m_flag = flag;
            data.m_value = anim;
            data.m_id = m_owner->GetId();
            msg.m_size = 8;
            msg.m_type = 0x3E;
            msg.m_data = &data;
            func_00200C00(conn, &msg);
        }
    }
    if (m_scene) {
        func_0013EB18(m_scene, anim, flag);
    }
    return true;
}
