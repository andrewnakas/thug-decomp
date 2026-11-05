extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022DE70(void* self, int index);
extern "C" void* func_0022E3C8(void* self, int index);
extern "C" void func_00205290(void* a, void* b);

bool Cmd_002207D8(void* params, void* script)
{
    int index;
    func_001E7DE8(params, 0x67E6859A, &index, 1);
    void* a = func_0022DE70(D_0038FC78, index);
    func_00205290(a, func_0022E3C8(D_0038FC78, index));
    return true;
}
