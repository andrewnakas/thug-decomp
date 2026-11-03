struct Vec1571C0 {
    float x, y, z;
};

struct Obj1571C0 {
    char m_pad[0x204];
    Vec1571C0** m204;
    void Get(int i, int j, float* x, float* y, float* z);
};

void Obj1571C0::Get(int i, int j, float* x, float* y, float* z)
{
    Vec1571C0* v = &m204[j][i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
