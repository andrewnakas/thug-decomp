/* fuzzy: 60.2 */
struct Data_002D6290 {
    char pad0[0x1C];
    char m1C[4];
};

struct LNode_002D6290 {
    int m0;
    Data_002D6290* m_data;
    LNode_002D6290* m_prev;
    LNode_002D6290* m_next;
    LNode_002D6290* Next()
    {
        LNode_002D6290* n = m_next;
        if (n->m_data == (Data_002D6290*)-1)
            return 0;
        return n;
    }
};

struct Iter_002D6290 {
    int m0;
    LNode_002D6290* m_cur;
    char* m8;
    Data_002D6290* Next()
    {
        m_cur = m_cur->Next();
        if (m_cur)
            return m_cur->m_data;
        return 0;
    }
    Data_002D6290* First(LNode_002D6290* head)
    {
        m_cur = head;
        return Next();
    }
};

struct Sel_002D6290 {
    char pad0[0x350];
    LNode_002D6290 m350;
    char pad360[8];
    Iter_002D6290 m368;
    Data_002D6290* m374;
};

struct Mgr_002D6290 {
    char pad0[8];
    Sel_002D6290* m8;
};

struct Script_002D6290 {
    char pad0[0x18];
    void* m18;
};

extern Mgr_002D6290* D_00392068;
extern char D_0037BEC0[];
extern "C" void func_001E7138(void* p, char* name, char* value);

bool Cmd_002D6290(void* params, Script_002D6290* script)
{
    Sel_002D6290* s = D_00392068->m8;
    s->m374 = s->m368.Next();
    if (!s->m374)
        s->m374 = s->m368.First(&s->m350);
    func_001E7138(script->m18, D_0037BEC0, s->m374->m1C);
    return true;
}
