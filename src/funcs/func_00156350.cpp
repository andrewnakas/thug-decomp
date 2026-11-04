struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00156350 {
    char pad[0x224];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00156350::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
