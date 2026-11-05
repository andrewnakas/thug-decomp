extern char D_0038F600[];
extern "C" unsigned int func_001F0D78(void* name);
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" void func_0010BFB8(int v);

bool func_002191E0(void* params, void* script)
{
    if (func_001E8708(params, func_001F0D78(D_0038F600)))
        func_0010BFB8(0);
    else
        func_0010BFB8(1);
    return true;
}
