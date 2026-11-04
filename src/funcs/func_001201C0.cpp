extern "C" void* func_001046B0(int size);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_001F0210(int a, int b, int c, int d, int e);

struct Heap_001201C0 {
    char pad[0xD8];
    void* mD8;
};

class C_001201C0 {
public:
    int m0;
    int m4;
    virtual ~C_001201C0();
};

extern "C" C_001201C0* func_0011F880(void* mem);
extern "C" void func_0011FA48(C_001201C0* o);
extern "C" void func_0011F930(C_001201C0* o, int arg);

extern Heap_001201C0* D_00388A70;
extern int D_00389518;
extern int D_0038951C;
extern C_001201C0* D_00389520;

void func_001201C0(int a0, int a1, int a2, int a3, int a4)
{
    D_00389518 = a2;
    D_0038951C = a3;
    D_00389520 = func_0011F880(func_001046B0(0x58));
    func_0011FA48(D_00389520);
    func_0010A950(D_00388A70, D_00388A70->mD8);
    func_0011F930(D_00389520, a1);
    func_0010A9B0(D_00388A70);
    func_001F0210(a4, 0, a0, 0, 0);
    D_00389518 = 0;
    D_0038951C = 0;
    if (D_00389520)
        delete D_00389520;
    D_00389520 = 0;
}
