struct Vec155550 {
    float x, y, z;
};

struct Obj155550 {
    char m_pad[0x200];
    Vec155550* m200;
    void Add(int i, float x, float y, float z);
};

void Obj155550::Add(int i, float x, float y, float z)
{
    Vec155550* v = &m200[i];
    v->x += x;
    v->y += y;
    v->z += z;
}
