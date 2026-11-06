struct Struct_001E87F0;
struct Comp_001E87F0 {
    unsigned char m0;
    unsigned char m_type;
    short m2;
    int m4;
    Struct_001E87F0* m_struct;
    Comp_001E87F0* m_next;
};
struct Struct_001E87F0 {
    int m0;
    Comp_001E87F0* m_head;
};

extern "C" bool func_001E87F0(Struct_001E87F0* s, Struct_001E87F0* target)
{
    if (target == s)
        return true;
    for (Comp_001E87F0* c = s->m_head; c; c = c->m_next) {
        if (c->m_type == 10 && func_001E87F0(c->m_struct, target))
            return true;
    }
    return false;
}
