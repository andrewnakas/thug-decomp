struct Vec1546D8 {
    float x, y, z;
};

struct Obj1546D8 {
    char m_pad[0x200];
    Vec1546D8* m200;
    void Get(int i, int a2, float* x, float* y, float* z);
};

void Obj1546D8::Get(int i, int a2, float* x, float* y, float* z)
{
    Vec1546D8* v = &m200[i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
