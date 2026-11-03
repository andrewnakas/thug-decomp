struct Vec157B68 {
    float x, y, z;
};

struct Obj157B68 {
    char m_pad[0x204];
    Vec157B68** m204;
    void Add(int i, int j, float x, float y, float z);
};

void Obj157B68::Add(int i, int j, float x, float y, float z)
{
    Vec157B68* v = &m204[j][i];
    v->x += x;
    v->y += y;
    v->z += z;
}
