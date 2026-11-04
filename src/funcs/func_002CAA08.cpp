extern void* D_00392808;
extern char D_00392878[];
extern char D_00392880[];
extern "C" int func_001E87B8(void* params, char* name);
extern "C" void func_002C6A40(void* p, int v);

extern "C" bool func_002CAA08(void* params)
{
    void* g = D_00392808;
    if (func_001E87B8(params, D_00392878))
        func_002C6A40(g, 1);
    else if (func_001E87B8(params, D_00392880))
        func_002C6A40(g, 0);
    return true;
}
