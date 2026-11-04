struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00158788 {
    char pad[0x218];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj00158788::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
