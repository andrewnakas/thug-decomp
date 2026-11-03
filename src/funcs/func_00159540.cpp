struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00159540 {
    char pad[0x218];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00159540::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
