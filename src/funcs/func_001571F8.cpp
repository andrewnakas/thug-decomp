struct Vec1571F8 {
    float x, y, z;
};

struct Obj1571F8 {
    char m_pad[0x204];
    Vec1571F8** m204;
    void Set(int i, int j, float x, float y, float z);
};

void Obj1571F8::Set(int i, int j, float x, float y, float z)
{
    Vec1571F8* v = &m204[j][i];
    v->x = x;
    v->y = y;
    v->z = z;
}
