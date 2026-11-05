extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, void** out, int required);
extern "C" void func_0023EC68(void* owner, int id, void* sub, void* script);

bool Cmd_00241F00(void* params, void* script)
{
    unsigned int id;
    void* sub;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    sub = 0;
    func_001E7C80(params, 0x7321A8D6, &sub, 0);
    func_0023EC68(func_00240850(), id, sub, script);
    return true;
}
