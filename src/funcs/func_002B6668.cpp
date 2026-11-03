extern void* D_00388A70;
extern int D_003925A0[];
extern int D_003925A8[];
extern char D_00379F18[];
extern char D_00379F28[];
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_0010D190(void* p, int type, int a, char* b);

struct Obj_002B6668 {
    char pad[0x10];
    void* m10;
    void* m14;
    int name[2];
    void Init(int a, int b, int in);
};

void Obj_002B6668::Init(int a, int b, int in)
{
    if (in) {
        __builtin_memcpy(name, D_003925A0, 7);
    } else {
        __builtin_memcpy(name, D_003925A8, 8);
    }
    char buf0[0x40];
    char buf1[0x40];
    func_003331D0(buf0, D_00379F18, (char*)name);
    func_003331D0(buf1, D_00379F28, (char*)name);
    m10 = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x30, a, buf0);
    m14 = func_0010D190(func_0010A638(D_00388A70, 0x5C, 1, 0), 0x1C, b, buf1);
}
