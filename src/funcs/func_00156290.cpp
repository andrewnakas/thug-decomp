struct Vec156290 {
    float x, y, z;
};

struct Obj156290 {
    char m_pad[0x200];
    Vec156290* m200;
    void Set(int i, float x, float y, float z);
};

void Obj156290::Set(int i, float x, float y, float z)
{
    Vec156290* v = &m200[i];
    v->x = x;
    v->y = y;
    v->z = z;
}
