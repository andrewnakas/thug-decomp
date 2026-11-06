struct Tex_00139D10 {
    unsigned int m_id;
    short m_refs;
};

extern char D_003C38C0[];
extern "C" void func_0013AB10(void* table, unsigned int* id);
extern "C" void func_0014A120(Tex_00139D10* t);

extern "C" bool func_00139D10(Tex_00139D10* t)
{
    if (--t->m_refs == 0) {
        unsigned int id = t->m_id;
        func_0013AB10(D_003C38C0, &id);
        func_0014A120(t);
        return true;
    }
    return false;
}
