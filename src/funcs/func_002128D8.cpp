extern char D_00370758[];
extern "C" int func_001E7F50(void* params, char* name, float* out, int req);
extern "C" void func_00144100(float v);

extern "C" int func_002128D8(void* params)
{
    float v;
    func_001E7F50(params, D_00370758, &v, 0);
    func_00144100(v);
    return 1;
}
