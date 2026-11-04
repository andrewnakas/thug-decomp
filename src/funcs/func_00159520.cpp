struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00159520 {
    char pad[0x218];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00159520::Set(int i, unsigned char v)
{
    m_colors[i].r = v;
}
