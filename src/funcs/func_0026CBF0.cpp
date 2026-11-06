typedef int qword __attribute__((mode(TI)));
struct Vec_0026CBF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Obj_0026CBF0 {
    char pad[0x20];
    Vec_0026CBF0 m20;
    Vec_0026CBF0 m30;
    void Set(const Vec_0026CBF0& a, const Vec_0026CBF0& b);
};

void Obj_0026CBF0::Set(const Vec_0026CBF0& a, const Vec_0026CBF0& b)
{
    m20 = a;
    m30 = b;
}
