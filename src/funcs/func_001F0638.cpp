struct MsgDesc_001F0638 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Packet_001F0638 {
    int m_type;
    int m_objId;
    int m_value;
    unsigned char m_flag;
};

struct Obj_001F0638 {
    char pad0[0x18];
    int m_id;
};

extern void* D_00392068;

extern "C" bool func_002A19A8(void* net);
extern "C" MsgDesc_001F0638* func_001FA800(MsgDesc_001F0638* desc);
extern "C" void* func_002A39E0(void* net, int a);
extern "C" void func_00200C00(void* conn, MsgDesc_001F0638* desc);

void func_001F0638(int type, Obj_001F0638* obj, int value, int flag)
{
    void* net = D_00392068;
    if (!func_002A19A8(net))
        return;
    Packet_001F0638 pkt;
    MsgDesc_001F0638 desc;
    func_001FA800(&desc);
    pkt.m_type = type;
    pkt.m_objId = -1;
    pkt.m_value = value;
    pkt.m_flag = flag;
    if (obj)
        pkt.m_objId = obj->m_id;
    void* conn = func_002A39E0(net, 0);
    desc.m_Length = sizeof(pkt);
    desc.m_Id = 0x49;
    desc.m_Data = &pkt;
    desc.m_Priority = 2;
    desc.m_Queue = 8;
    func_00200C00(conn, &desc);
}
