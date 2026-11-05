extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_0023BB78(void* owner, int id);

bool Cmd_002408E0(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_0023BB78(owner, id);
    return true;
}
