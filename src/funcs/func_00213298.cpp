extern int D_0038F338;
extern void* D_0038FC78;

extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int a);
extern "C" void func_0022BEE8(int a);
extern "C" void func_0020B0A0(unsigned int crc, int a, int b);
extern "C" void* func_0022DE70(void* game, int i);
extern "C" void func_00203F18(void* skater, int a);
extern "C" void* func_0022BFE0();
extern "C" void func_0022B940(void* p);

bool Cmd_00213298(void* params, void* script)
{
    int v;
    func_001E7DE8(params, 0, &v, 1);
    D_0038F338 = v;
    func_0022BEE8(v);
    if (D_0038F338 == 0)
        func_0020B0A0(0x967C138C, 0, 0);
    else
        func_0020B0A0(0xEB17151B, 0, 1);
    for (int i = 0; i < 8; i++) {
        void* s = func_0022DE70(D_0038FC78, i);
        if (s)
            func_00203F18(s, D_0038F338);
    }
    void* p = func_0022BFE0();
    if (p)
        func_0022B940(p);
    return true;
}
