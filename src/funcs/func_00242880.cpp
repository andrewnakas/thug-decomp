extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" bool func_0023CBF0(void* owner, int id, bool flag);

bool Cmd_00242880(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    bool flag = func_001E8708(params, 0x9AC8D54F);
    return func_0023CBF0(func_00240850(), id, flag);
}
