struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00153D80 {
    char pad[0x220];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00153D80::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
