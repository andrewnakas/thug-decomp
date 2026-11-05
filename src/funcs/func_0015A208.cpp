struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj0015A208 {
    char pad[0x228];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj0015A208::Set(int i, unsigned char v)
{
    m_colors[i].r = v;
}
