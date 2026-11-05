struct Heap_0013C8A8 {
    char pad[0xE4];
    void* mE4;
};

extern "C" void func_0010A950(Heap_0013C8A8* heap, void* sub);
extern "C" void func_0010A9B0(Heap_0013C8A8* heap);
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern Heap_0013C8A8* D_00388A70;

struct Geom_0013C8A8;
extern "C" int func_0013C7E0(Geom_0013C8A8* g);
extern "C" void func_0013C830(Geom_0013C8A8* g, void* buf);

struct Geom_0013C8A8 {
    int m0;
    int m4;
    int m8;
    void* mC;
    void GetColors(void* out);
};

void Geom_0013C8A8::GetColors(void* out)
{
    int n = func_0013C7E0(this);
    if (!mC) {
        func_0010A950(D_00388A70, D_00388A70->mE4);
        mC = func_0010BDE0(n * 4);
        func_0010A9B0(D_00388A70);
        func_0013C830(this, mC);
    }
    func_00331404(out, mC, n * 4);
}
