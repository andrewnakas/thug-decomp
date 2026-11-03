struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00157298 {
    char pad[0x218];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj00157298::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
