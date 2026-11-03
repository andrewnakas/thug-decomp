extern "C" void func_001E7C80(void* params, int name, int* out, int required);
extern "C" void* func_00240850();
extern "C" int func_0023D6A8(void* mgr, int value);

int Cmd_002417A0(void* params, void* script)
{
    int value;
    func_001E7C80(params, 0, &value, 1);
    return func_0023D6A8(func_00240850(), value);
}
