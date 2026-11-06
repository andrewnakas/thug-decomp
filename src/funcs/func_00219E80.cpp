extern void* D_0038C608;
extern "C" bool func_001E8248(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void func_00186D60(void* p, void* a, void* b, int c);

extern "C" bool func_00219E80(void* params, void* script)
{
    void* a = 0;
    func_001E8248(params, 0x11B70A02, &a, 1);
    void* b = 0;
    func_001E8180(params, 0x7031F10C, &b, 0);
    func_00186D60(D_0038C608, a, b, 1);
    return true;
}
