struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00159598 {
    char pad[0x228];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00159598::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
