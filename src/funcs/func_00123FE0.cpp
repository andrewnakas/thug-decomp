struct Rgba_00123FE0 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_00123FE0(const Rgba_00123FE0& o) { v = o.v; }
};

struct Sub_00123FE0 {
    char pad[0x48];
    Rgba_00123FE0 m48;
    char pad4C[4];
    void Set(Rgba_00123FE0 c)
    {
        m48.v.r = c.v.r;
        m48.v.g = c.v.g;
        m48.v.b = c.v.b;
        m48.v.a = c.v.a;
    }
};

struct C_00123FE0 {
    char pad[0xC];
    unsigned int mC;
    char pad10[0x70];
    Sub_00123FE0 m80;
    Sub_00123FE0 mD0;
    Rgba_00123FE0 GetColor() const { return mD0.m48; }
    void SetColor(const Rgba_00123FE0& c, int both);
};

void C_00123FE0::SetColor(const Rgba_00123FE0& c, int both)
{
    Rgba_00123FE0 cur = GetColor();
    if (cur.v.r != c.v.r || cur.v.g != c.v.g || cur.v.b != c.v.b || cur.v.a != c.v.a) {
        mD0.Set(c);
        mC |= 0x400;
    }
    if (both) {
        m80.Set(c);
        mC |= 0x400;
    }
}
