struct Vec157B00 {
    float x, y, z;
};

struct Obj157B00 {
    char m_pad[0x204];
    Vec157B00** m204;
    void Get(int i, int j, float* x, float* y, float* z);
};

void Obj157B00::Get(int i, int j, float* x, float* y, float* z)
{
    Vec157B00* v = &m204[j][i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
