extern int D_0038F370;
extern int D_0038F374;
extern char D_0036FFF8[];
extern char D_0036FFD8[];

extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" int func_0020C1E8(int start);
extern "C" void func_00103F28(const char* fmt, ...);

bool Cmd_0020C328(void* params)
{
    if (func_001E8708(params, 0x1A4E0EF9)) {
        D_0038F370 = 0;
        D_0038F374 = 0;
    }
    if (D_0038F370 == 0) {
        D_0038F374 = func_0020C1E8(1);
        func_00103F28(D_0036FFD8);
        D_0038F370 = 1;
        return true;
    }
    int t = func_0020C1E8(0);
    func_00103F28(D_0036FFF8, D_0038F374 - t + 200000);
    return true;
}
