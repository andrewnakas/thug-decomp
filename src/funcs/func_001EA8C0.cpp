struct Comp_001EA8C0 {
    unsigned char m0;
    unsigned char m_type;
    unsigned char m2;
    char pad3[5];
    int m_value;
    int mC;
};

extern "C" Comp_001EA8C0* func_001E5040(int id);

extern "C" void func_001EA8C0(Comp_001EA8C0* c, int* type, int* value)
{
    *value = c->m_value;
    *type = c->m_type;
    if (*type == 13) {
        Comp_001EA8C0* r = func_001E5040(*value);
        if (r) {
            *value = r->mC;
            *type = r->m2;
        }
    }
}
