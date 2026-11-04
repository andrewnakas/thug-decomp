struct Chan153240 {
    unsigned char a, b, c, d;
};

struct Obj153240 {
    char pad[0x210];
    Chan153240 m210[4];
    void SetD(int i, unsigned char v);
};

void Obj153240::SetD(int i, unsigned char v)
{
    m210[i].d = v >> 1;
}
