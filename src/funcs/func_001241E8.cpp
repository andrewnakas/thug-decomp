extern "C" void func_00183CB8(void* obj, void** ref);

struct Ref_001241E8 {
    void* m_p;
    Ref_001241E8(const Ref_001241E8& o);
    ~Ref_001241E8()
    {
        if (m_p) {
            func_00183CB8(m_p, &m_p);
            m_p = 0;
        }
    }
};

extern "C" Ref_001241E8 func_00125308(void* self, int a, void* b);

extern "C" void* func_001241E8(void* self, int a, void* b)
{
    return func_00125308(self, a, b).m_p;
}
