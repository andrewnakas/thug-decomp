extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E358(void* self);
extern "C" void func_0024F3F0(void* obj, bool v);

bool Cmd_002208F0(void* params, void* script)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_0024F3F0(func_0022E358(D_0038FC78), v != 0);
    return true;
}
