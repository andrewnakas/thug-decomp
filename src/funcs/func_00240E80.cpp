extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_0023CF38(void* owner, int id, unsigned int a, int b);

bool Cmd_00240E80(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    unsigned int a;
    int b;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_001E8398(params, 0, &a, 1);
    func_001E7DE8(params, 0, &b, 1);
    return func_0023CF38(owner, id, a, b);
}
