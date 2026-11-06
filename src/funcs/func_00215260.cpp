extern void* D_00392068;

extern "C" bool func_001E7DE8(void* params, int name, int* out, int required);
extern "C" void func_002A1898(void* mgr, int mode);

bool Cmd_00215260(void* params)
{
    void* mgr = D_00392068;
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    if (v == 0)
        func_002A1898(mgr, 0);
    else if (v == 1)
        func_002A1898(mgr, 1);
    else if (v == 2)
        func_002A1898(mgr, 2);
    return true;
}
