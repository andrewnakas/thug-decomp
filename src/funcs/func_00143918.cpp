struct Fx_00143918 {
    int m0;
    char pad4[0xC];
    unsigned int b0 : 1;
};

extern "C" void func_00144508(void* table);
extern "C" Fx_00143918* func_00144518(void* table, int a);
extern "C" void func_0014F2F8(Fx_00143918* fx);
extern void* D_0038A630;

extern "C" void func_00143918(int id, int flag)
{
    func_00144508(D_0038A630);
    Fx_00143918* fx = func_00144518(D_0038A630, 0);
    if (fx) {
        do {
            if (id == fx->m0 && (flag & 1) == fx->b0)
                func_0014F2F8(fx);
            fx = func_00144518(D_0038A630, 0);
        } while (fx);
    }
}
