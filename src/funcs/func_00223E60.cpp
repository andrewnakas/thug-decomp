struct MsgDesc_00223E60 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Packet_00223E60 {
    unsigned char m_a;
    unsigned int m_b;
};

extern void* D_00392068;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" MsgDesc_00223E60* func_001FA800(MsgDesc_00223E60* desc);
extern "C" void* func_002A39E0(void* net, int a);
extern "C" void func_00200C00(void* conn, MsgDesc_00223E60* desc);

bool func_00223E60(void* params)
{
    MsgDesc_00223E60 desc;
    Packet_00223E60 pkt;
    unsigned int a;
    unsigned int b;
    void* net = D_00392068;
    func_001E8398(params, 0x5B24FAAA, &a, 1);
    func_001E8398(params, 0x81CFF663, &b, 1);
    void* conn = func_002A39E0(net, 0);
    if (conn) {
        func_001FA800(&desc);
        pkt.m_a = a;
        pkt.m_b = b;
        desc.m_Id = 0x89;
        desc.m_Data = &pkt;
        desc.m_Length = sizeof(pkt);
        desc.m_Priority = 2;
        desc.m_Queue = 8;
        func_00200C00(conn, &desc);
    }
    return true;
}
