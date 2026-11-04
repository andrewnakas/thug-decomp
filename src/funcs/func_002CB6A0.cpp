extern char D_00392860[];
extern char D_003928D8[];

extern "C" int func_001E7D18(void* p, char* name, char** out, int v);
extern "C" void func_001E7E58(void* p, char* name, int* out, int v);
extern "C" void func_001E8180(void* p, unsigned int key, int* out, int v);
extern "C" void* func_002C95E0(int v);
extern "C" void func_002C84F8(void* p, char* s, int v);
extern "C" void func_002C8568(void* p, int v);

int func_002CB6A0(void* params)
{
    char* s = 0;
    func_001E7D18(params, D_00392860, &s, 0);
    int n = -1;
    func_001E7E58(params, D_003928D8, &n, 0);
    func_002C84F8(func_002C95E0(1), s, n);
    int f = 0;
    func_001E8180(params, 0x049EC3F9, &f, 0);
    func_002C8568(func_002C95E0(1), f);
    return 1;
}
