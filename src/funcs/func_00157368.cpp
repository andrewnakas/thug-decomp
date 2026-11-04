struct Rgba157368 {
    unsigned char r, g, b, a;
};

struct Obj157368 {
    char m_pad[0x220];
    Rgba157368* m220;
    void SetG(int i, unsigned char v);
};

void Obj157368::SetG(int i, unsigned char v)
{
    m220[i].g = v;
}
