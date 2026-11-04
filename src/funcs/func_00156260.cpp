struct Vec156260 {
    float x, y, z;
};

struct Obj156260 {
    char m_pad[0x200];
    Vec156260* m200;
    void Get(int i, int a2, float* x, float* y, float* z);
};

void Obj156260::Get(int i, int a2, float* x, float* y, float* z)
{
    Vec156260* v = &m200[i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
