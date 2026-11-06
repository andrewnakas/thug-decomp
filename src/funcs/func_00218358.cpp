extern char D_00370E48[];
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8618(void* a, void* b);
extern "C" bool func_001E8708(void* a, void* b);

extern "C" bool func_00218358(void* params, void* script)
{
    void* a;
    void* b;
    if (func_001E81F0(params, D_00370E48, &a, 0)) {
        func_001E8398(params, 0, &b, 0);
        if (func_001E8618(a, b))
            return true;
        return func_001E8708(a, b);
    }
    return false;
}
