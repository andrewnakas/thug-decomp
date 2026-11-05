extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_0023BC10(void* owner, int id, bool flag);

int Cmd_002409A8(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    bool flag = func_001E8708(params, 0x9AC8D54F);
    return func_0023BC10(owner, id, flag);
}
