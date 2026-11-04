struct Vec1586B0 {
    float x, y, z;
};

struct Obj1586B0 {
    char m_pad[0x204];
    Vec1586B0** m204;
    void Get(int i, int j, float* x, float* y, float* z);
};

void Obj1586B0::Get(int i, int j, float* x, float* y, float* z)
{
    Vec1586B0* v = &m204[j][i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
