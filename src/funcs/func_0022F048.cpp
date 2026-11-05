struct Mgr_0022F048 {
    char pad[0x8C];
    int m_8C;
};

extern Mgr_0022F048* D_0038FC78;
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);

bool Cmd_0022F048(void* params, void* script)
{
    int v;
    func_001E8A30(params, 0, &v, 1);
    return v == D_0038FC78->m_8C;
}
