struct Vec1594C8 {
    float x, y, z;
};

struct Obj1594C8 {
    char m_pad[0x204];
    Vec1594C8** m204;
    void Add(int i, int j, float x, float y, float z);
};

void Obj1594C8::Add(int i, int j, float x, float y, float z)
{
    Vec1594C8* v = &m204[j][i];
    v->x += x;
    v->y += y;
    v->z += z;
}
