extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" void func_00253F08(void* p, bool on);
extern void* D_00390828;

bool Cmd_00254FC0(void* params, void* script)
{
    int v = 1;
    func_001E88D8(params, 0, &v, 0);
    func_00253F08(D_00390828, v != 0);
    return true;
}
