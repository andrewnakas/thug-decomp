extern char D_00390A00[];
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);

bool Fn_002584A0(void* params)
{
    unsigned int v;
    func_001E84E8(params, D_00390A00, &v, 0);
    return v == 0x1806DDF8;
}
