struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00157C28 {
    char pad[0x220];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00157C28::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
