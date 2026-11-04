struct Vec155500 {
    float x, y, z;
};

struct Obj155500 {
    char m_pad[0x200];
    Vec155500* m200;
    void Get(int i, int a2, float* x, float* y, float* z);
};

void Obj155500::Get(int i, int a2, float* x, float* y, float* z)
{
    Vec155500* v = &m200[i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
