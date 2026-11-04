struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00153230 {
    char pad[0x210];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00153230::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
