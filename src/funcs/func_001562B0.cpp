struct Vec1562B0 {
    float x, y, z;
};

struct Obj1562B0 {
    char m_pad[0x200];
    Vec1562B0* m200;
    void Add(int i, float x, float y, float z);
};

void Obj1562B0::Add(int i, float x, float y, float z)
{
    Vec1562B0* v = &m200[i];
    v->x += x;
    v->y += y;
    v->z += z;
}
