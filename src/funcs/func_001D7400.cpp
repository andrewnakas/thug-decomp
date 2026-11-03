typedef int qword __attribute__((mode(TI)));

struct Obj_001D7400 {
    char m_pad[0x10];
    qword m_10;
    char m_pad2[0xB4 - 0x20];
    int m_B4;
    void Set(const qword* v);
};

void Obj_001D7400::Set(const qword* v)
{
    m_10 = *v;
    m_B4 = 1;
}
