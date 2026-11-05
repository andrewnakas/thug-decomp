extern void* D_00392068;
extern char D_0038F610[];
extern "C" int func_001E8890(void* params, void* name, int* out, int req);
extern "C" void func_002A3600(void* o, int v);

bool func_00216638(void* params, void* script)
{
    void* o = D_00392068;
    int v;
    func_001E8890(params, D_0038F610, &v, 1);
    func_002A3600(o, v);
    return true;
}
