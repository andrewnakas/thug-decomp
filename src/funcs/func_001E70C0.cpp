struct Comp_001E70C0 {
    unsigned char m0;
    unsigned char m_type;
    short m2;
    int m_name;
    char* m_str;
    int mC;
};

extern "C" void* func_001E8CD0(unsigned int size);
extern "C" Comp_001E70C0* func_001E4ED8(void* mem);
extern "C" char* func_001E4DE0(const char* s);
extern "C" void func_001E6F90(void* params, Comp_001E70C0* c);

extern "C" void func_001E70C0(void* params, int name, const char* str)
{
    Comp_001E70C0* c = func_001E4ED8(func_001E8CD0(0x10));
    c->m_name = name;
    c->m_type = 3;
    c->m_str = func_001E4DE0(str);
    func_001E6F90(params, c);
}
