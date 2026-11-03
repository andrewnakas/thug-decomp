struct Info_002B8AA0 {
    char pad[0x28];
    int m28;
    int m2C;
};

struct EBase_002B8AA0 {
    int m0;
    int m4;
    EBase_002B8AA0* m_next;
    virtual void A();
    virtual ~EBase_002B8AA0();
};

struct Elem_002B8AA0 : EBase_002B8AA0 {
    int m10;
    Info_002B8AA0* m14;
};

extern "C" void func_001333D8(void* p, int id);

struct Obj_002B8AA0 {
    int m0;
    EBase_002B8AA0* m4;
    int m8;
    int mC;
    char pad[0x18 - 0x10];
    void* m18;
    char pad2[0x9C - 0x1C];
    int m9C;
    int mA0;
    void Remove(Elem_002B8AA0* e, int keep);
};

void Obj_002B8AA0::Remove(Elem_002B8AA0* e, int keep)
{
    if (!(e->m4 & 4)) {
        EBase_002B8AA0* prev = 0;
        EBase_002B8AA0* c = m4;
        while (c) {
            if (c == e) {
                if (prev)
                    prev->m_next = e->m_next;
                else
                    m4 = e->m_next;
                break;
            }
            prev = c;
            c = prev->m_next;
        }
        if (!(e->m4 & 0x100)) {
            m9C -= e->m14->m28;
            mA0 -= e->m14->m2C;
        }
    }
    if (!keep)
        func_001333D8(m18, e->m0);
    mC--;
    if (e)
        delete e;
    if (!m4)
        m0 &= ~8;
    m0 |= 0x40;
}
