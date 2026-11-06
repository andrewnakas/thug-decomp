struct Comp_001E7200 {
    unsigned char m0;
    unsigned char m_type;
    short m2;
    unsigned int m_name;
    int m_value;
};
extern "C" void* func_001E8CD0(int size);
extern "C" Comp_001E7200* func_001E4ED8(void* p);
extern "C" void func_001E6F90(void* s, Comp_001E7200* c);

extern "C" void func_001E7200(void* s, unsigned int name, int value)
{
    Comp_001E7200* c = func_001E4ED8(func_001E8CD0(0x10));
    c->m_name = name;
    c->m_type = 1;
    c->m_value = value;
    func_001E6F90(s, c);
}
