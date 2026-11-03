struct Mem_002150C0 {
    char pad[0xDC];
    void* m_top;
};

extern Mem_002150C0* D_00388A70;
extern void* D_00392068;
extern void* D_0038FC78;
extern char D_003709B8[];

extern "C" void func_0010A950(Mem_002150C0* mem, void* heap);
extern "C" void func_0010A9B0(Mem_002150C0* mem);
extern "C" bool func_002A1A38(void* net);
extern "C" bool func_002A19A8(void* net);
extern "C" int func_002A18E0(void* net);
extern "C" void* func_0022E358(void* game);
extern "C" unsigned int func_0024F6F8(void* p);
extern "C" void* func_002A2AE8(void* net, int a, int b, int c, int index);
extern "C" void func_002A2CA0(void* net, int a, unsigned long ip, unsigned short port, int index);
extern "C" void func_00235878(void* game, void* conn, int index);
extern "C" void func_001F0370(const char* name, void* params, int a, int b);
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" unsigned int func_00326E30(const char* ip);

bool Cmd_002150C0(void* params, void* script)
{
    void* net = D_00392068;
    void* game = D_0038FC78;
    func_0010A950(D_00388A70, D_00388A70->m_top);
    if (func_002A1A38(net)) {
        unsigned int count = func_0024F6F8(func_0022E358(game));
        for (unsigned int i = 0; i < count; i++) {
            void* conn = func_002A2AE8(net, 0, 1, 1, i);
            func_002A2CA0(net, 0, 0, 0, i);
            func_00235878(game, conn, i);
            if (func_002A19A8(net)) {
                func_001F0370(D_003709B8, 0, 0, 0);
            }
        }
    } else {
        const char* ip = 0;
        int port = 0;
        func_001E8870(params, 0, &ip, 0);
        func_001E7DE8(params, 0, &port, 0);
        bool host = func_002A18E0(net) == 1;
        if (ip && port) {
            func_002A2AE8(net, 0, 0, 1, 0);
            func_002A2CA0(net, host, func_00326E30(ip), port, 0);
        }
    }
    func_0010A9B0(D_00388A70);
    return true;
}
