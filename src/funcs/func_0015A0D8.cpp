struct Vec15A0D8 {
    float x, y, z;
};

struct Obj15A0D8 {
    char m_pad[0x204];
    Vec15A0D8** m204;
    void Add(int i, int j, float x, float y, float z);
};

void Obj15A0D8::Add(int i, int j, float x, float y, float z)
{
    Vec15A0D8* v = &m204[j][i];
    v->x += x;
    v->y += y;
    v->z += z;
}
