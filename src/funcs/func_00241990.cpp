extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_0023DF88(void* owner, int id, int v);

bool Cmd_00241990(void* params, void* script)
{
    unsigned int id;
    int v;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_001E7DE8(params, 0, &v, 1);
    return func_0023DF88(func_00240850(), id, v);
}
