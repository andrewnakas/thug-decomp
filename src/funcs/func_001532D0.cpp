struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001532D0 {
    char pad[0x230];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001532D0::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
