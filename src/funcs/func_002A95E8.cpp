extern void* D_00392068;
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" void func_002A18E8(void* p, int mode);

extern "C" bool func_002A95E8(void* params)
{
    void* g = D_00392068;
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    func_002A18E8(g, v);
    return true;
}
