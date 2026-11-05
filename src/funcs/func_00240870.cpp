extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" bool func_0023B5A8(void* owner, int id, int v);

bool Cmd_00240870(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    int v;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_001E8180(params, 0x7031F10C, &v, 1);
    return func_0023B5A8(owner, id, v);
}
