extern "C" int func_003331D0(char* buf, char* fmt, char* name);
extern "C" void* func_0010E1E8(char* path, int* size, int a, int b);
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" void func_0010BEB8(void* p);

extern char D_0035CBF0[];
extern char D_0035CC00[];

struct C_00122E40 {
    int m0;
    int m4;
    char pad8[0x38];
    char m40[0x4420];
    void Load(char* name, int alt);
};

void C_00122E40::Load(char* name, int alt)
{
    char path[0x200];
    int size;
    if (alt)
        func_003331D0(path, D_0035CBF0, name);
    else
        func_003331D0(path, D_0035CC00, name);
    void* data = func_0010E1E8(path, &size, 0, 0);
    func_00331404(m40, data, size);
    func_0010BEB8(data);
    m4 = 1;
}
