/* fuzzy: 67.6 */
struct Skater_001A2480 {
    long m0;
    char pad8[0x1B0 - 0x8];
    unsigned int m_b0 : 1;
    unsigned int m_b1 : 1;
    unsigned int m_b2 : 1;
    bool Bit1() const { return m_b1; }
    bool Bit2() const { return m_b2; }
    bool Check() const
    {
        bool c = false;
        if (Bit1())
            c = !Bit2();
        return c;
    }
};

struct Owner_001A2480 {
    char pad0[0x260];
    Skater_001A2480* m260;
};

struct Obj_001A2480 {
    char pad0[0x70];
    Owner_001A2480* m70;
    bool Fn();
};

bool Obj_001A2480::Fn()
{
    Skater_001A2480* s = m70->m260;
    bool r = false;
    if (s) {
        bool c = s->Check();
        r = c;
    }
    return r;
}
