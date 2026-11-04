struct Rgba157380 {
    unsigned char r, g, b, a;
};

struct Obj157380 {
    char m_pad[0x220];
    Rgba157380* m220;
    void SetB(int i, unsigned char v);
};

void Obj157380::SetB(int i, unsigned char v)
{
    m220[i].b = v;
}
