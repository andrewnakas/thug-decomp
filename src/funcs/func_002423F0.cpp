extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" bool func_0024A280(void* item, int v);

bool Cmd_002423F0(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    int v;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_001E7DE8(params, 0, &v, 1);
    return func_0024A280(func_0023BAD8(owner, id, 1), v);
}
