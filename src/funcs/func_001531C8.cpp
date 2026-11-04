struct Vec1531C8 {
    float x, y, z;
};

struct Obj1531C8 {
    char m_pad[0x200];
    Vec1531C8* m200;
    void Add(int i, float x, float y, float z);
};

void Obj1531C8::Add(int i, float x, float y, float z)
{
    Vec1531C8* v = &m200[i];
    v->x += x;
    v->y += y;
    v->z += z;
}
