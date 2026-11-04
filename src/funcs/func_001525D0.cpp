struct Vec1525D0 {
    float x, y, z;
};

struct Obj1525D0 {
    char m_pad[0x200];
    Vec1525D0* m200;
    void Add(int i, float x, float y, float z);
};

void Obj1525D0::Add(int i, float x, float y, float z)
{
    Vec1525D0* v = &m200[i];
    v->x += x;
    v->y += y;
    v->z += z;
}
