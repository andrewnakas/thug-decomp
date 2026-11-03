struct Chan153210 {
    unsigned char a, b, c, d;
};

struct Obj153210 {
    char pad[0x210];
    Chan153210 m210[4];
    void SetA(int i, unsigned char v);
};

void Obj153210::SetA(int i, unsigned char v)
{
    m210[i].a = v;
}
