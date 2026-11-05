extern "C" void* func_00240850();
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_0023E980(void* owner, int flag);

bool Cmd_00241E10(void* params, void* script)
{
    void* owner = func_00240850();
    func_0023E980(owner, func_001E8708(params, 0x5685C1B7));
    return true;
}
