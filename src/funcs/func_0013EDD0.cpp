typedef int qword __attribute__((mode(TI)));

struct Vec_0013EDD0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

class Mesh_0013EDD0 {
public:
    char pad0[0xF0];
    Vec_0013EDD0 mF0;
    char pad100[0xB0];
    unsigned long b0 : 1;
    unsigned long b1 : 1;
    unsigned long b2 : 1;
    unsigned long b3 : 1;
    unsigned long b4 : 1;
    unsigned long b5 : 1;
    short m1B2;
    int m1B4;
    virtual ~Mesh_0013EDD0();
    bool SetColor(const Vec_0013EDD0* c);
};

bool Mesh_0013EDD0::SetColor(const Vec_0013EDD0* c)
{
    mF0 = *c;
    b3 = !(c->x == 1.0f && c->y == 1.0f && c->z == 1.0f);
    return true;
}
