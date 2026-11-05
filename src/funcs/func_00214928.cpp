extern char D_0038F590[];
extern char D_0038F580[];

extern "C" int func_001E84E8(void* params, const char* name, unsigned int* out, int req);
extern "C" void func_001F0A18(unsigned int a);
extern "C" void func_001F0AB0(unsigned int b);

bool Cmd_00214928(void* params, void* script)
{
    unsigned int a = 0;
    if (func_001E84E8(params, D_0038F590, &a, 0)) {
        func_001F0A18(a);
        return true;
    }
    unsigned int b = 0;
    if (func_001E84E8(params, D_0038F580, &b, 0))
        func_001F0AB0(b);
    return true;
}
