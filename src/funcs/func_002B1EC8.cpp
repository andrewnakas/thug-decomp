struct Heap_002B1EC8 {
    char pad0[0xFC];
    int mFC;
};

extern Heap_002B1EC8* D_00388A70;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Obj_002B1EC8_S {
    char pad[0x18];
    unsigned char m18;
};

struct Obj_002B1EC8 {
    char pad[0x18];
    Obj_002B1EC8_S* m18;
    char pad2[0x164 - 0x1C];
    unsigned char* m164;
    void SetData(const void* src, int len);
};

void Obj_002B1EC8::SetData(const void* src, int len)
{
    func_0010A950(D_00388A70, D_00388A70->mFC);
    unsigned char c = m18->m18;
    m164 = (unsigned char*)func_0010A638(D_00388A70, len + 1, 1, 0);
    m164[0] = c;
    func_00331404(m164 + 1, src, len);
    func_0010A9B0(D_00388A70);
}
