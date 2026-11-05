extern "C" void* func_00240850();
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_0023C048(void* owner, int flag);

bool Cmd_00240CD8(void* params, void* script)
{
    void* owner = func_00240850();
    return func_0023C048(owner, func_001E8708(params, 0xA21884B5)) > 0;
}
