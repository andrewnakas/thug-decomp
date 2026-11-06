struct Heap_0014CA78 {
    char pad[0xD8];
    int mD8;
};

extern Heap_0014CA78* D_00388A70;
extern char D_0038AD68[];
extern char D_0035F5D0[];
extern char D_0035F5E0[];
extern char D_0038AD70[];
extern char D_0038AD78[];

extern "C" void* func_00110E38(const char* name, const char* mode);
extern "C" long func_00110980(void* f);
extern "C" void func_0010A950(Heap_0014CA78* h, int a);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010A9B0(Heap_0014CA78* h);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" int func_00110EF8(void* f);
extern "C" void func_0010BEB8(void* p);
extern "C" int func_001E5400(const char* name, int a);
extern "C" void func_00103F28(const char* fmt, ...);

struct Anim_0014CA78 {
    char pad[0xB0];
    int mB0;
    bool LoadFile(const char* name);
};

extern "C" bool func_0014C9B0(Anim_0014CA78* self, void* data);

bool Anim_0014CA78::LoadFile(const char* name)
{
    void* f = func_00110E38(name, D_0038AD68);
    int size = func_00110980(f);
    func_0010A950(D_00388A70, D_00388A70->mD8);
    void* buf = func_0010BDE0(size);
    func_0010A9B0(D_00388A70);
    func_00110F68(buf, size, 1, f);
    func_00110EF8(f);
    bool ok = func_0014C9B0(this, buf);
    func_0010BEB8(buf);
    if (func_001E5400(D_0035F5D0, 0)) {
        func_00103F28(D_0035F5E0, name, mB0);
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            if (mB0 & mask) func_00103F28(D_0038AD70, i);
        }
        func_00103F28(D_0038AD78);
    }
    return ok;
}
