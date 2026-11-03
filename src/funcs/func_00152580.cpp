struct Vec152580 {
    float x, y, z;
};

struct Obj152580 {
    char m_pad[0x200];
    Vec152580* m200;
    void Get(int i, int a2, float* x, float* y, float* z);
};

void Obj152580::Get(int i, int a2, float* x, float* y, float* z)
{
    Vec152580* v = &m200[i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
