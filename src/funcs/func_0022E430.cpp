extern char D_00372C48[];
extern char D_00372C58[];
extern char D_00371C78[];
extern char D_00366B58[];
extern char D_003714C0[];
extern void* D_00392068;

struct Iter_0022E430 {
    int m_0;
    int m_4;
    void* m_vtbl;
};

struct Game_0022E430 {
    char pad[0x64];
    int m_64;
    char pad68[0x348];
    unsigned int m_level;
};

extern "C" void func_0010BFC0(char* name);
extern "C" void func_0010BFC8();
extern "C" bool func_002A19A8(void* net);
extern "C" bool func_002A1A38(void* net);
extern "C" void* func_002A53F8(void* net, Iter_0022E430* it, int a);
extern "C" void* func_002A5490(void* net, Iter_0022E430* it, int a);
extern "C" void func_002B2F40(void* p, int a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001F0210(unsigned int key, void* params, int a, int b, int c);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" void* func_002A39D8(void* net);
extern "C" void* func_00200EC0(void* client, Iter_0022E430* it);
extern "C" void* func_00200EF8(void* client, Iter_0022E430* it);
extern "C" void func_00202688(void* conn, int timeout);
extern "C" bool func_002A5520(void* net, Iter_0022E430* it);
extern "C" void func_002A8598(void* net);

void func_0022E430(Game_0022E430* game, unsigned int level)
{
    void* net = D_00392068;
    func_0010BFC0(D_00372C48);
    if (func_002A19A8(net) && func_002A1A38(net)) {
        Iter_0022E430 it;
        it.m_4 = 0;
        it.m_vtbl = D_00371C78;
        for (void* p = func_002A53F8(net, &it, 1); p; p = func_002A5490(net, &it, 1))
            func_002B2F40(p, 0);
        it.m_vtbl = D_00371C78;
    }
    if (level != func_001F0D78(D_00372C58))
        func_001F0210(level, 0, 0, 0, 0);
    game->m_level = level;
    game->m_64 = 1;
    if (func_002A19A8(net)) {
        for (int i = 0; i < 2; i++) {
            Iter_0022E430 it;
            it.m_vtbl = D_00366B58;
            it.m_4 = 0;
            void* client = func_002A39E0(net, i);
            if (client) {
                void* conn = func_00200EC0(client, &it);
                if (conn)
                    func_00202688(conn, 12000);
            }
            it.m_vtbl = D_00366B58;
        }
        if (func_002A1A38(net)) {
            Iter_0022E430 it;
            it.m_vtbl = D_00366B58;
            it.m_4 = 0;
            void* client = func_002A39D8(net);
            if (client) {
                for (void* c = func_00200EC0(client, &it); c; c = func_00200EF8(client, &it))
                    func_00202688(c, 8000);
            }
            it.m_vtbl = D_00366B58;
        } else {
            Iter_0022E430 it;
            it.m_4 = 0;
            it.m_vtbl = D_003714C0;
            if (!func_002A5520(net, &it))
                func_002A8598(net);
            it.m_vtbl = D_003714C0;
        }
    }
    func_0010BFC8();
}
