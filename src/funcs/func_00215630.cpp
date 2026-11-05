extern void* D_00392068;
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void func_002A7AF0(void* o, int v);

bool func_00215630(void* params, void* script)
{
    void* o = D_00392068;
    int v = 0;
    func_001E8398(params, 0x86068BD9, &v, 0);
    func_002A7AF0(o, v);
    return true;
}
