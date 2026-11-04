struct Heap_0026D0E0 {
    char pad0[0xEC];
    int mEC;
};

extern Heap_0026D0E0* D_00388A70;
extern int* D_00394154;
extern char D_00376268[];
extern char D_003762A8[];
extern "C" void func_0026D080();
extern "C" void func_0010A950(void* heap, int a);
extern "C" void func_0010A9B0(void* heap);
extern "C" bool func_001E5400(char* name, int a);
extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_0022A720(unsigned int a, unsigned int b, void (*fn)());

void func_0026D0E0(int* p)
{
    func_0010A950(D_00388A70, D_00388A70->mEC);
    D_00394154 = p;
    *p = 1;
    if (func_001E5400(D_00376268, 0)) {
        func_00103F28(D_003762A8);
    }
    func_0022A720(0x2CA8A299, 0xE5399FB2, func_0026D080);
    func_0010A9B0(D_00388A70);
}
