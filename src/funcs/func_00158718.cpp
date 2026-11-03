struct Vec158718 {
    float x, y, z;
};

struct Obj158718 {
    char m_pad[0x204];
    Vec158718** m204;
    void Add(int i, int j, float x, float y, float z);
};

void Obj158718::Add(int i, int j, float x, float y, float z)
{
    Vec158718* v = &m204[j][i];
    v->x += x;
    v->y += y;
    v->z += z;
}
