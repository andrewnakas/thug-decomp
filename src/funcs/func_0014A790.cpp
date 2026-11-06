struct Tex_0014A790 {
    int m0;
    int m4;
    int m8;
};

struct Anim_0014A790 {
    char pad[0x1C];
    int m1C;
    int m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    int m34;
    int m38;
};

struct Elem_0014A790 {
    Tex_0014A790* m0;
    int m4;
    float m8;
    float mC;
    float m10;
    float m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    char pad28[0x14];
    Anim_0014A790* m3C;
    void Sync();
};

void Elem_0014A790::Sync()
{
    Tex_0014A790* t = m0;
    m3C->m20 = m4;
    if (t) m3C->m1C = t->m8;
    m3C->m24 = m8;
    m3C->m28 = mC;
    m3C->m2C = m10;
    m3C->m30 = m14;
    m3C->m34 = m20;
    m3C->m38 = m24;
}
