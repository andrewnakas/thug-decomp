extern char D_0038F630[];
extern int D_0038FC78;

struct Ref_002169F8;
extern "C" void func_00183CB8(void* obj, Ref_002169F8* ref);
extern "C" void func_00183C98(void* obj, Ref_002169F8* ref);
extern "C" bool func_001E87B8(void* params, char* flag);
extern "C" void* func_0022DD38(int id);

struct Ref_002169F8 {
    void* m_p;
    void Set(void* p)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = p;
        if (p)
            func_00183C98(p, this);
    }
};

struct Script_002169F8 {
    char m_pad[0xBC];
    Ref_002169F8 m_ref;
};

bool Cmd_002169F8(void* params, Script_002169F8* script)
{
    if (func_001E87B8(params, D_0038F630))
        script->m_ref.Set(0);
    else
        script->m_ref.Set(func_0022DD38(D_0038FC78));
    return true;
}
