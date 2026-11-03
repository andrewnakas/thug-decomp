typedef int qword __attribute__((mode(TI)));

struct Obj_001D7338 {
    char m_pad[0x10];
    qword m_10;
    void Set(const qword* v);
};

void Obj_001D7338::Set(const qword* v)
{
    m_10 = *v;
}
