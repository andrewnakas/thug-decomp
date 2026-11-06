extern "C" void func_00183CB8(void* obj, void** ref);

struct Ref_00124238 {
    void* m_p;
    Ref_00124238(const Ref_00124238& o);
    ~Ref_00124238()
    {
        if (m_p) {
            func_00183CB8(m_p, &m_p);
            m_p = 0;
        }
    }
};

extern "C" Ref_00124238 func_00125308(void* self, int a, unsigned int* b);

extern "C" void* func_00124238(void* self, unsigned int id)
{
    return func_00125308(self, 0, &id).m_p;
}
