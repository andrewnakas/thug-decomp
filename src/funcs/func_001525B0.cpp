struct Vec1525B0 {
    float x, y, z;
};

struct Obj1525B0 {
    char m_pad[0x200];
    Vec1525B0* m200;
    void Set(int i, float x, float y, float z);
};

void Obj1525B0::Set(int i, float x, float y, float z)
{
    Vec1525B0* v = &m200[i];
    v->x = x;
    v->y = y;
    v->z = z;
}
