extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_00243FB0(void* obj);

bool Cmd_002428E0(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_00243FB0(func_0023BAD8(func_00240850(), id, 1));
    return true;
}
