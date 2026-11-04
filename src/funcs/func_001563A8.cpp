struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001563A8 {
    char pad[0x230];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001563A8::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
