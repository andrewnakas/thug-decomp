extern int D_0038F338;
extern void* D_0038FC78;

extern "C" void* func_0022BFE0();
extern "C" void func_0022BEE8(int a);
extern "C" void func_0020B0A0(unsigned int crc, int a, int b);
extern "C" void* func_0022DE70(void* game, int i);
extern "C" void func_00203F18(void* skater, int a);
extern "C" void func_0022BF00(void* p);
extern "C" void func_001E93D0(void* params, int a);
extern "C" void func_0022B8A8(void* p, void* params);

bool Cmd_002174E0(void* params, void* script)
{
    void* p = func_0022BFE0();
    D_0038F338 = 1;
    func_0022BEE8(1);
    if (D_0038F338 == 0)
        func_0020B0A0(0x967C138C, 0, 0);
    else
        func_0020B0A0(0xEB17151B, 0, 1);
    for (int i = 0; i < 8; i++) {
        void* s = func_0022DE70(D_0038FC78, i);
        if (s)
            func_00203F18(s, D_0038F338);
    }
    if (p) {
        func_0022BF00(p);
        func_001E93D0(params, 0);
        func_0022B8A8(p, params);
    }
    return true;
}
