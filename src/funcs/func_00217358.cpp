extern char D_00370CC0[];
extern "C" int func_001E87B8(void* params, void* name);
extern "C" void func_001F0FB8();

bool func_00217358(void* params, void* script)
{
    if (!func_001E87B8(params, D_00370CC0))
        func_001F0FB8();
    return true;
}
