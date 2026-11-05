struct Sym_001EE1F0 {
    int m_flags;
    unsigned int m_name;
};

extern "C" Sym_001EE1F0* func_001E5258(Sym_001EE1F0* prev);
extern "C" void* func_001EE410(void* prev);
extern "C" int func_001EFFE8(void* obj, unsigned int name);
extern "C" void func_001EEBA8(void* obj);

extern "C" void func_001EE1F0()
{
    Sym_001EE1F0* s = func_001E5258(0);
    while (s) {
        if ((s->m_flags & 0xFF0100) == 0x70100) {
            for (void* o = func_001EE410(0); o; o = func_001EE410(o)) {
                if (func_001EFFE8(o, s->m_name))
                    func_001EEBA8(o);
            }
            s->m_flags &= ~0x100;
        }
        s = func_001E5258(s);
    }
}
