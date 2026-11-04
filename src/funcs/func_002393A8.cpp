struct Obj_002393A8 {
    short pad0;
    short m_id;
};

struct Packet_002393A8 {
    char m_one;
    char m_b;
    int m_id;
    int m_arg;
    int m_count;
    char m_data[0x800];
};

struct MsgDesc_002393A8 {
    char m_msgId;
    unsigned short m_length;
    void* m_data;
    int pad8;
    int m_priority;
    char m_queue;
};

extern void* D_00392068;
extern void* D_0038FC78;
extern char D_00373700[];
extern char D_00373720[];

extern "C" void func_001FA800(MsgDesc_002393A8* desc);
extern "C" char* func_002A52F0(void* mgr, unsigned short id);
extern "C" void* func_002A39E0(void* mgr, int conn);
extern "C" char func_002A7660(void* mgr);
extern "C" void* func_0022DF08(void* game, int id);
extern "C" void* func_00185578(void* obj, unsigned int key);
extern "C" unsigned int func_001B0F58(void* comp, void* buf, int size);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00200B30(void* conn, int msgId, int len, void* data, char* name, int queue, int a, int b);

void func_002393A8(Obj_002393A8* obj, int arg)
{
    Packet_002393A8 pkt;
    MsgDesc_002393A8 desc;
    void* mgr = D_00392068;
    func_001FA800(&desc);
    void* conn = func_002A39E0(mgr, *(int*)(*(char**)(func_002A52F0(mgr, obj->m_id) + 0x18) + 0x320));
    pkt.m_one = 1;
    pkt.m_id = obj->m_id;
    pkt.m_arg = arg;
    pkt.m_b = func_002A7660(mgr);
    unsigned int size = func_001B0F58(func_00185578(func_0022DF08(D_0038FC78, obj->m_id), 0x270F56E1), pkt.m_data, 0x800);
    pkt.m_count = size >> 2;
    func_00103F28(D_00373700, size >> 2);
    desc.m_length = size + 0x10;
    desc.m_msgId = 0x3B;
    desc.m_priority = 2;
    desc.m_queue = 8;
    desc.m_data = &pkt;
    func_00200B30(conn, desc.m_msgId, desc.m_length, desc.m_data, D_00373720, desc.m_queue, 1, 0);
}
