struct Mgr_002169A0 {
    char m_pad0[0x84];
    void* m84;
};

extern Mgr_002169A0* D_0038FC78;
extern char D_0038F610[];
extern char D_0038F628[];
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" void func_0026EE40(void* obj, char* s);

bool Cmd_002169A0(void* params, void* script)
{
    void* obj = D_0038FC78->m84;
    char* s = D_0038F628;
    func_001E8890(params, D_0038F610, &s, 0);
    func_0026EE40(obj, s);
    return true;
}
