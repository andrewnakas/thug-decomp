struct Heap_002125A0 {
    char pad0[0x11C];
    void* m_11C;
};

struct Array_002125A0 {
    char pad0[0xC];
    unsigned int m_size;
};

extern Heap_002125A0* D_00388A70;
extern char D_003F57E8[];
extern char D_003706F0[];

extern "C" void func_0010A950(Heap_002125A0* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_002125A0* mgr);
extern "C" void func_00229340(const char* name, int a);
extern "C" Array_002125A0* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(Array_002125A0* a, unsigned int i);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_002125A0()
{
    func_0010A950(D_00388A70, D_00388A70->m_11C);
    func_00229340(D_003F57E8, 0);
    Array_002125A0* a = func_001E55B8(0xC472ECC5, 0);
    for (unsigned int i = 0; i < a->m_size; i++)
        func_001E7268(func_001E9378(a, i), D_003706F0, i);
    func_0010A9B0(D_00388A70);
    return true;
}
