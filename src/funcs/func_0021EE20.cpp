struct Obj_0021EE20 {
    int m0;
    char m_sub[4];
};

extern void* D_0038FC78;
extern char D_00371768[];

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Obj_0021EE20* func_0022E3C8(void* mgr, int id);
extern "C" bool func_001E81F0(void* params, char* name, int* out, int required);
extern "C" void func_0011FAB8(void* sub, int name, int flag);

bool Cmd_0021EE20(void* params)
{
    int id;
    func_001E7DE8(params, 0x67E6859A, &id, 1);
    void* sub = func_0022E3C8(D_0038FC78, id)->m_sub;
    int name;
    func_001E81F0(params, D_00371768, &name, 1);
    func_0011FAB8(sub, name, 1);
    return true;
}
