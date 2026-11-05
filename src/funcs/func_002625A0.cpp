/* sym: __11It_002625A0 = 0x00261078 */
struct Heap_002625A0 {
    char pad[0x3EC];
    int m3EC;
};

extern Heap_002625A0* D_00388A70;
extern char D_00375C00[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void* func_00263320(void* p, const int& k, int* out);
extern "C" void* func_001046B0(int size);
extern "C" void* func_002610C0(void* dst, void* src);

struct It_002625A0 {
    int m[25];
    It_002625A0();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Obj_002625A0 {
    int m0;
    char m4[0x18];
    It_002625A0* m1C[2];
    void Fn();
};

void Obj_002625A0::Fn()
{
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    func_001F0370(D_00375C00, 0, 0, 0);
    int found;
    m1C[0] = (It_002625A0*)func_00263320(m4, 0, &found);
    for (int i = 1; i < 2; i++) {
        m1C[i] = new It_002625A0;
        func_002610C0(m1C[i], func_00263320(m4, i, &found));
    }
    func_0010A9B0(D_00388A70);
}
