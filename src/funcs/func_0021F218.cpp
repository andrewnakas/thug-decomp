extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" char* func_0022E3C8(void* mgr, int id);
extern "C" void* func_001200E0(void* p);
extern "C" int func_00123420(void* o);

int Cmd_0021F218(void* params, void* script)
{
    int id;
    func_001E7DE8(params, 0x67E6859A, &id, 1);
    void* o = func_001200E0(func_0022E3C8(D_0038FC78, id) + 4);
    if (o)
        return func_00123420(o);
    return 0;
}
