struct Mgr_002A9588;
extern Mgr_002A9588* D_00392068;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_002A18D8(Mgr_002A9588* m, int v);

bool func_002A9588(void* params, void* script)
{
    Mgr_002A9588* m = D_00392068;
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    if (!v)
        func_002A18D8(m, 0);
    else
        func_002A18D8(m, 1);
    return true;
}
