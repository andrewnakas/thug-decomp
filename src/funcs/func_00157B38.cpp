struct Vec157B38 {
    float x, y, z;
};

struct Obj157B38 {
    char m_pad[0x204];
    Vec157B38** m204;
    void Set(int i, int j, float x, float y, float z);
};

void Obj157B38::Set(int i, int j, float x, float y, float z)
{
    Vec157B38* v = &m204[j][i];
    v->x = x;
    v->y = y;
    v->z = z;
}
