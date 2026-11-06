extern void* D_0038C7B0;
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00189C68(void* mgr, bool def, int size);

bool func_0018A5C0(void* params)
{
    int size = 0x400;
    int r = func_001E7DE8(params, 0, &size, 0);
    func_00189C68(D_0038C7B0, !r, size);
    return true;
}
