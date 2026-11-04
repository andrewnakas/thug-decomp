struct Vec1586E8 {
    float x, y, z;
};

struct Obj1586E8 {
    char m_pad[0x204];
    Vec1586E8** m204;
    void Set(int i, int j, float x, float y, float z);
};

void Obj1586E8::Set(int i, int j, float x, float y, float z)
{
    Vec1586E8* v = &m204[j][i];
    v->x = x;
    v->y = y;
    v->z = z;
}
