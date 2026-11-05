typedef int qword __attribute__((mode(TI)));

struct Vec_0011E0D0 {
    qword q;
};

struct Entry_0011E0D0 {
    int m0[8];
    Vec_0011E0D0 m_pos;
};

extern "C" Entry_0011E0D0* func_0011D4F0(void* self, int key);

bool GetPos_0011E0D0(void* self, int key, Vec_0011E0D0* out)
{
    Entry_0011E0D0* e = func_0011D4F0(self, key);
    if (e)
        *out = e->m_pos;
    return e != 0;
}
