struct Vec153C68 {
    float x, y, z;
};

struct Obj153C68 {
    char m_pad[0x200];
    Vec153C68* m200;
    void Set(int i, float x, float y, float z);
};

void Obj153C68::Set(int i, float x, float y, float z)
{
    Vec153C68* v = &m200[i];
    v->x = x;
    v->y = y;
    v->z = z;
}
