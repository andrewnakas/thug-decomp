struct Heap_0011F380 {
    char pad[0xD8];
    void* mD8;
};

extern "C" void* func_00110E38(char* name, char* mode);
extern "C" long func_00110980(void* f);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010BDE0(int size);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" void func_0010BEB8(void* buf);
extern "C" void func_00110EF8(void* f);
extern "C" int func_003364D8(char* a, char* b);

extern Heap_0011F380* D_00388A70;
extern char D_00389448[];
extern char D_00389450[];

struct C_0011F380 {
    char pad[0x490];
    unsigned int m490;
    int Load(char* name, int arg);
};

extern "C" int func_0011ED50(C_0011F380* o, void* buf, int size, int arg);
extern "C" void func_0011F178(C_0011F380* o, char* name);

int C_0011F380::Load(char* name, int arg)
{
    int ok = 0;
    void* f = func_00110E38(name, D_00389448);
    void* buf = 0;
    if (f) {
        int size = func_00110980(f);
        func_0010A950(D_00388A70, D_00388A70->mD8);
        buf = func_0010BDE0(size);
        func_0010A9B0(D_00388A70);
        if (func_00110F68(buf, size, 1, f) && func_0011ED50(this, buf, size, arg)) {
            if (func_003364D8(name, D_00389450))
                m490 |= 1;
            ok = 1;
        }
    }
    if (buf)
        func_0010BEB8(buf);
    func_00110EF8(f);
    func_0011F178(this, name);
    return ok;
}
