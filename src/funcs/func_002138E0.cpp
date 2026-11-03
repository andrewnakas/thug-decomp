extern "C" void func_001E7DE8(void* params, int name, int* out, int required);

bool Cmd_002138E0(void* params, void* script)
{
    int value = 0;
    func_001E7DE8(params, 0, &value, 0);
    return true;
}
