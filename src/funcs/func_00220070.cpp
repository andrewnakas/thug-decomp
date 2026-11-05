struct Mgr_00220070 {
    char pad[0x394];
    void* m_obj;
};

extern Mgr_00220070* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_00252160(void* obj, int v);

bool Cmd_00220070(void* params, void* script)
{
    int v;
    func_001E7DE8(params, 0, &v, 0);
    return func_00252160(D_0038FC78->m_obj, v);
}
