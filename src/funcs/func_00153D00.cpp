struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00153D00 {
    char pad[0x210];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00153D00::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
