struct Vec154728 {
    float x, y, z;
};

struct Obj154728 {
    char m_pad[0x200];
    Vec154728* m200;
    void Add(int i, float x, float y, float z);
};

void Obj154728::Add(int i, float x, float y, float z)
{
    Vec154728* v = &m200[i];
    v->x += x;
    v->y += y;
    v->z += z;
}
