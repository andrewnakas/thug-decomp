extern void* D_00392068;
extern char D_00370B48[];
extern "C" int func_001E87B8(void* params, void* name);
extern "C" void func_002B4E20(void* o, int v);

bool func_00215D50(void* params, void* script)
{
    void* o = D_00392068;
    func_002B4E20(o, func_001E87B8(params, D_00370B48));
    return true;
}
