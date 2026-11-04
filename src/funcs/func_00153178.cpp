struct Vec153178 {
    float x, y, z;
};

struct Obj153178 {
    char m_pad[0x200];
    Vec153178* m200;
    void Get(int i, int a2, float* x, float* y, float* z);
};

void Obj153178::Get(int i, int a2, float* x, float* y, float* z)
{
    Vec153178* v = &m200[i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
