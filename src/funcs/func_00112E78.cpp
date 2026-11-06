struct Mgr_00112E78;
extern Mgr_00112E78* D_00388EFC;
extern int D_00388F00;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" Mgr_00112E78* func_00112F10(void* p);

extern "C" Mgr_00112E78* func_00112E78(int create)
{
    if (!D_00388EFC && create) {
        D_00388EFC = func_00112F10(func_00104760(0x84, 0, 1));
    }
    D_00388F00++;
    return D_00388EFC;
}
