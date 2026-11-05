extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_0023BEF8(void* owner, int id, int v);

bool Cmd_00240DD8(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    return func_0023BEF8(owner, id, 0);
}
