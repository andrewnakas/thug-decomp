extern "C" void* func_00240850();
extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" void func_0023C298(void* owner, bool flag);

bool Cmd_00240B68(void* params, void* script)
{
    void* owner = func_00240850();
    func_0023C298(owner, func_001E8618(params, 0xCC365298));
    return true;
}
