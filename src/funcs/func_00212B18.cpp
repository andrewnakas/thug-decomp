extern char D_0038F4F8[];
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void* func_001317D0(unsigned int id);
extern "C" void func_00135530(void* p, int on);

extern "C" bool func_00212B18(void* params, void* script)
{
    unsigned int id;
    func_001E84E8(params, D_0038F4F8, &id, 0);
    func_00135530(func_001317D0(id), 1);
    return true;
}
