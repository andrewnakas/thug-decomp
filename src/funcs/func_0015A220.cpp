struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj0015A220 {
    char pad[0x228];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj0015A220::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
