extern char D_003924B8[];
extern char D_00379A10[];
extern char D_00379C30[];

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002B4D80 {
    void Launch(int flag);
};

void Obj_002B4D80::Launch(int flag)
{
    void* p = func_001E6978(func_001190D0(8));
    if (flag) {
        func_001E73C8(p, D_003924B8, func_001F0D78(D_003924B8));
    }
    func_001F0370(D_00379A10, p, 0, 0);
    func_001F0370(D_00379C30, p, 0, 0);
    if (p) {
        func_001E6AE8(p, 3);
    }
}
