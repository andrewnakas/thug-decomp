extern void* D_00392068;
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_002A7938(void* net, int a, int b);

extern "C" bool func_00215570(void* params, void* script)
{
    int a = 0;
    int b = 0;
    void* net = D_00392068;
    func_001E8398(params, 0x90FF204D, &a, 0);
    func_001E8398(params, 0xDE64FC3E, &b, 0);
    return func_002A7938(net, a, b);
}
