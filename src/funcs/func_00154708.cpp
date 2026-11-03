struct Vec154708 {
    float x, y, z;
};

struct Obj154708 {
    char m_pad[0x200];
    Vec154708* m200;
    void Set(int i, float x, float y, float z);
};

void Obj154708::Set(int i, float x, float y, float z)
{
    Vec154708* v = &m200[i];
    v->x = x;
    v->y = y;
    v->z = z;
}
