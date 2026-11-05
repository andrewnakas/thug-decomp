typedef int qword __attribute__((mode(TI)));

struct Src_001D5260 {
    int m0;
    char pad4[0xC];
    qword m10;
    qword m20;
};

struct Obj_001D5260 {
    int m0;
    int m4;
    Src_001D5260* m8;
    char padC[0xB0 - 0xC];
    qword mB0;
    qword mC0;
    void Set(Src_001D5260* s);
};

void Obj_001D5260::Set(Src_001D5260* s)
{
    m8 = s;
    if (s) m0 = s->m0;
    mB0 = m8->m10;
    mC0 = m8->m20;
}
