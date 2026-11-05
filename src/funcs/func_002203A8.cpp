struct Mgr_002203A8 {
    char pad[0x398];
    void* m_obj;
};

extern Mgr_002203A8* D_0038FC78;
extern "C" bool func_001E88D8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" int func_00252270(void* obj);

bool Cmd_002203A8(void* params, void* script)
{
    int v;
    if (!func_001E88D8(params, 0, &v, 0)) {
        func_001E8A30(params, 0, &v, 1);
    }
    return func_00252270(D_0038FC78->m_obj) == v;
}
