typedef int qword __attribute__((mode(TI)));
union Vec_0026BF28 {
    qword q;
    float c[4];
    Vec_0026BF28& operator=(const Vec_0026BF28& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_0026BF28 {
    Vec_0026BF28 r[4];
};

extern "C" Mat_0026BF28* func_00135120(void* p);

struct Obj_0026BF28 {
    char pad[0x48];
    int m48;
    char pad2[0x54 - 0x4C];
    void* m54;
    char pad3[0x60 - 0x58];
    Vec_0026BF28 m60;
    Vec_0026BF28 m70;
    void Attach(void* p);
};

void Obj_0026BF28::Attach(void* p)
{
    m54 = p;
    if (p && m48 == 1) {
        Mat_0026BF28* m = func_00135120(p);
        m60 = m->r[0];
        m70 = m->r[1];
    }
}
