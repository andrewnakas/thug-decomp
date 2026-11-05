extern char D_0038F590[];
extern char D_0038F6C0[];

extern "C" int func_001E84E8(void* params, const char* name, unsigned int* out, int req);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" void func_00141368(unsigned int a);
extern "C" void func_00141310(unsigned int a);

bool Cmd_00218238(void* params, void* script)
{
    unsigned int a = 0;
    func_001E84E8(params, D_0038F590, &a, 0);
    int b = 0;
    func_001E7E58(params, D_0038F6C0, &b, 0);
    if (b)
        func_00141368(a);
    else
        func_00141310(a);
    return true;
}
