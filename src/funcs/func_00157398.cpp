struct Rgba157398 {
    unsigned char r, g, b, a;
};

struct Obj157398 {
    char m_pad[0x220];
    Rgba157398* m220;
    void SetA(int i, unsigned char v);
};

void Obj157398::SetA(int i, unsigned char v)
{
    m220[i].a = v >> 1;
}
