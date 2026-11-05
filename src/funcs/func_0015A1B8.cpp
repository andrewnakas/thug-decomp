struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj0015A1B8 {
    char pad[0x224];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj0015A1B8::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
