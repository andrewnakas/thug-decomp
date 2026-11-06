typedef int qword __attribute__((mode(TI)));

struct Vec_0014F4B8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Rgba_0014F4B8 {
    unsigned char r, g, b, a;
};

struct Vert_0014F4B8 {
    Vec_0014F4B8 pos;
    Rgba_0014F4B8 col;
    float u;
    float v;
    Vert_0014F4B8& operator=(const Vert_0014F4B8& o)
    {
        pos = o.pos;
        col = o.col;
        u = o.u;
        v = o.v;
        return *this;
    }
};

struct Tri_0014F4B8 {
    Vert_0014F4B8 v[3];
};

struct Obj_0014F4B8 {
    char pad0[0x410];
    Tri_0014F4B8 m410[1];
    void Fn(int i);
};

void Obj_0014F4B8::Fn(int i)
{
    m410[i].v[1] = m410[i].v[0];
    m410[i].v[2] = m410[i].v[0];
}
