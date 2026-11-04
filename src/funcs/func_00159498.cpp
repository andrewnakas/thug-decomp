struct Vec159498 {
    float x, y, z;
};

struct Obj159498 {
    char m_pad[0x204];
    Vec159498** m204;
    void Set(int i, int j, float x, float y, float z);
};

void Obj159498::Set(int i, int j, float x, float y, float z)
{
    Vec159498* v = &m204[j][i];
    v->x = x;
    v->y = y;
    v->z = z;
}
