struct Vec155530 {
    float x, y, z;
};

struct Obj155530 {
    char m_pad[0x200];
    Vec155530* m200;
    void Set(int i, float x, float y, float z);
};

void Obj155530::Set(int i, float x, float y, float z)
{
    Vec155530* v = &m200[i];
    v->x = x;
    v->y = y;
    v->z = z;
}
