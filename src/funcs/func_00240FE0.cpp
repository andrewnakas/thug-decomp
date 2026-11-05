extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_0023CFB8(void* owner, int id, unsigned int v);

bool Cmd_00240FE0(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    unsigned int v;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_001E8398(params, 0x2E0B1465, &v, 1);
    return func_0023CFB8(owner, id, v);
}
