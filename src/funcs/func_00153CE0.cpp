struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00153CE0 {
    char pad[0x210];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00153CE0::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
