extern char D_0038FCC8[];
extern char D_00372D88[];
extern char D_00372D98[];
extern char D_00372DA8[];
extern char D_00372DB8[];
extern char D_00372DC8[];
extern char D_00371C78[];
extern void* D_00392068;

struct MsgDesc_0022F080 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Iter_0022F080 {
    int m_0;
    int m_4;
    void* m_vtbl;
};

struct Msg_0022F080 {
    unsigned int m_level;
    unsigned char m_warn;
};

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_001E8A30(void* params, unsigned int key, unsigned int* out, int required);
extern "C" unsigned int func_002A76F0(void* net);
extern "C" void func_002A7650(void* net, unsigned int level);
extern "C" bool func_001E86D0(void* params, char* name);
extern "C" void func_001DEEE0();
extern "C" void* func_002A39D8(void* net);
extern "C" void* func_002A53F8(void* net, Iter_0022F080* it, int a);
extern "C" void* func_002A5490(void* net, Iter_0022F080* it, int a);
extern "C" void func_001FA800(MsgDesc_0022F080* desc);
extern "C" int func_0010FC30();
extern "C" bool func_002B1FC8(void* player);
extern "C" int func_002B3080(void* player);
extern "C" void* func_002C0368();
extern "C" void* func_002BCE20(void* a, int b);
extern "C" void func_00200998(void* client, int conn, int id, int size, void* data, char* name, int queue, int a, int b);
extern "C" void* func_0029C320();
extern "C" void* func_0029A2C8(void* a);
extern "C" void func_001FF970(void* client, int conn, MsgDesc_0022F080* desc);
extern "C" bool func_002AB438(void* net);
extern "C" void func_002AB468(void* net, unsigned int level);
extern "C" int func_002AB4C8(void* net);
extern "C" void* func_002AB4C0(void* net);
extern "C" void func_002B2FC0(void* player, int time);
extern "C" bool func_002A19A8(void* net);
extern "C" void func_002010D0(void* client, int a);

bool func_0022F080(void* params)
{
    void* net = D_00392068;
    Msg_0022F080 msg;
    Iter_0022F080 it;
    MsgDesc_0022F080 desc;
    unsigned int level;
    int time;
    func_001E8A30(params, func_001F0D78(D_0038FCC8), &level, 1);
    if (level == func_001F0D78(D_00372D88))
        level = func_002A76F0(net);
    func_002A7650(net, level);
    bool warn = func_001E86D0(params, D_00372D98);
    func_001DEEE0();
    it.m_4 = 0;
    it.m_vtbl = D_00371C78;
    void* client = func_002A39D8(net);
    msg.m_warn = warn;
    msg.m_level = level;
    for (void* p = func_002A53F8(net, &it, 1); p; p = func_002A5490(net, &it, 1)) {
        func_001FA800(&desc);
        time = func_0010FC30();
        if (!func_002B1FC8(p) && level == 0xB664035D) {
            int conn = func_002B3080(p);
            func_00200998(client, conn, 0x6C, 15000, func_002BCE20(func_002C0368(), 0), D_00372DA8, 8, 0, 1);
            conn = func_002B3080(p);
            func_0029C320();
            func_00200998(client, conn, 0x88, 0x1132, func_0029A2C8(func_0029C320()), D_00372DB8, 8, 0, 1);
        }
        desc.m_Data = &msg;
        desc.m_Id = 0x46;
        desc.m_Priority = 2;
        desc.m_Length = 8;
        desc.m_Queue = 8;
        func_001FF970(client, func_002B3080(p), &desc);
        if (!func_002B1FC8(p) && func_002AB438(net)) {
            func_002AB468(net, level);
            int conn = func_002B3080(p);
            int size = func_002AB4C8(net) & 0xFFFF;
            func_00200998(client, conn, 0x87, size, func_002AB4C0(net), D_00372DC8, 8, 0, 1);
        }
        desc.m_Data = &time;
        desc.m_Length = 4;
        desc.m_Id = 0x25;
        func_001FF970(client, func_002B3080(p), &desc);
        func_002B2FC0(p, time);
    }
    if (!func_002A19A8(net))
        func_002010D0(client, 0);
    it.m_vtbl = D_00371C78;
    return true;
}
