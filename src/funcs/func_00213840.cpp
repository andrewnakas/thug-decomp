extern int D_0039425C;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

extern "C" bool func_00213840(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0x6835B854, &v, 0);
    D_0039425C = v;
    return true;
}
