struct Vec1531A8 {
    float x, y, z;
};

struct Obj1531A8 {
    char m_pad[0x200];
    Vec1531A8* m200;
    void Set(int i, float x, float y, float z);
};

void Obj1531A8::Set(int i, float x, float y, float z)
{
    Vec1531A8* v = &m200[i];
    v->x = x;
    v->y = y;
    v->z = z;
}
