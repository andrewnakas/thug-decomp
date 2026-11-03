struct Vec159460 {
    float x, y, z;
};

struct Obj159460 {
    char m_pad[0x204];
    Vec159460** m204;
    void Get(int i, int j, float* x, float* y, float* z);
};

void Obj159460::Get(int i, int j, float* x, float* y, float* z)
{
    Vec159460* v = &m204[j][i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
