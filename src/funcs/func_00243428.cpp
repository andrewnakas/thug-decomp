extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" bool func_00240340(void* owner, int flag, unsigned int v);

bool Cmd_00243428(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int v = 0;
    func_001E8398(params, 0x5D82C486, &v, 0);
    return func_00240340(owner, func_001E8708(params, 0x68977CD7), v);
}
