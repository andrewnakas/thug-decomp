struct Vec15A070 {
    float x, y, z;
};

struct Obj15A070 {
    char m_pad[0x204];
    Vec15A070** m204;
    void Get(int i, int j, float* x, float* y, float* z);
};

void Obj15A070::Get(int i, int j, float* x, float* y, float* z)
{
    Vec15A070* v = &m204[j][i];
    *x = v->x;
    *y = v->y;
    *z = v->z;
}
