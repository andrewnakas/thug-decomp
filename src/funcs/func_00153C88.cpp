struct Vec153C88 {
    float x, y, z;
};

struct Obj153C88 {
    char m_pad[0x200];
    Vec153C88* m200;
    void Add(int i, float x, float y, float z);
};

void Obj153C88::Add(int i, float x, float y, float z)
{
    Vec153C88* v = &m200[i];
    v->x += x;
    v->y += y;
    v->z += z;
}
