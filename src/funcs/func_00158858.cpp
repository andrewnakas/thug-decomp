struct Rgba158858 {
    unsigned char r, g, b, a;
};

struct Obj158858 {
    char m_pad[0x220];
    Rgba158858* m220;
    void SetG(int i, unsigned char v);
};

void Obj158858::SetG(int i, unsigned char v)
{
    m220[i].g = v;
}
