struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00154810 {
    char pad[0x230];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00154810::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
