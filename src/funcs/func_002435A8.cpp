extern "C" void* func_00240850();
extern "C" void* func_0023BB00(void* owner, void* params, int create);
extern "C" void func_0024E9B0(void* obj);

bool Cmd_002435A8(void* params, void* script)
{
    func_0024E9B0(func_0023BB00(func_00240850(), params, 1));
    return true;
}
