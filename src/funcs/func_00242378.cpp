extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_0023EE50(void* owner);
extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" bool func_0024A5F0(void* item, unsigned int v);

bool Cmd_00242378(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int v;
    func_001E8398(params, 0xA1DC81F9, &v, 1);
    int id = func_0023EE50(owner);
    if (id) {
        return func_0024A5F0(func_0023BAD8(owner, id, 1), v);
    }
    return false;
}
