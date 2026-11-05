struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00157C60 {
    char pad[0x228];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00157C60::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
