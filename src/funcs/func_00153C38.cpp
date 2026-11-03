struct Vec153C38 {
    float x, y, z;
};

struct Obj153C38 {
    char m_pad[0x200];
    Vec153C38* m200;
    void Get(int i, int a2, float* x, float* y, float* z);
};

void Obj153C38::Get(int i, int a2, float* x, float* y, float* z)
{
    Vec153C38* v = &m200[i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
