extern void* D_00392068;
extern int D_0038F33C;

class Iter_002164A8 {
public:
    void* m_node;
    int m_index;
    Iter_002164A8() : m_index(0) {}
    virtual ~Iter_002164A8() {}
    virtual void Run();
};

struct MsgDesc_002164A8 {
    char m_msgId;
    unsigned short m_length;
    void* m_data;
    int pad8;
    int m_priority;
    char m_queue;
};

struct Packet_002164A8 {
    int m_value;
    char m_flag;
};

struct Conn_002164A8 {
    char pad[0x48];
    int m_handle;
};

extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" void* func_002A39D8(void* net);
extern "C" Conn_002164A8* func_00200EC0(void* mgr, Iter_002164A8* it);
extern "C" Conn_002164A8* func_00200EF8(void* mgr, Iter_002164A8* it);
extern "C" bool func_00202778(Conn_002164A8* conn);
extern "C" MsgDesc_002164A8* func_001FA800(MsgDesc_002164A8* desc);
extern "C" void func_001FF970(void* mgr, int handle, MsgDesc_002164A8* desc);

bool Cmd_002164A8(void* params, void* script)
{
    Iter_002164A8 it;
    int value;
    MsgDesc_002164A8 desc;
    Packet_002164A8 pkt;
    void* net = D_00392068;
    func_001E8A30(params, 0xAE94C183, &value, 1);
    bool flag = func_001E8618(params, 0xF649D637) != 0;
    D_0038F33C = value;
    void* mgr = func_002A39D8(net);
    for (Conn_002164A8* conn = func_00200EC0(mgr, &it); conn; conn = func_00200EF8(mgr, &it)) {
        if (func_00202778(conn)) {
            func_001FA800(&desc);
            pkt.m_value = value;
            pkt.m_flag = flag;
            desc.m_msgId = 0x7F;
            desc.m_priority = 2;
            desc.m_data = &pkt;
            desc.m_length = 8;
            desc.m_queue = 8;
            func_001FF970(mgr, conn->m_handle, &desc);
            D_0038F33C = value;
        }
    }
    D_0038F33C = value;
    return true;
}
