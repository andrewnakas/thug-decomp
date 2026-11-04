struct Vec157228 {
    float x, y, z;
};

struct Obj157228 {
    char m_pad[0x204];
    Vec157228** m204;
    void Add(int i, int j, float x, float y, float z);
};

void Obj157228::Add(int i, int j, float x, float y, float z)
{
    Vec157228* v = &m204[j][i];
    v->x += x;
    v->y += y;
    v->z += z;
}
