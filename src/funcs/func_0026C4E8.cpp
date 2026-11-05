typedef int qword __attribute__((mode(TI)));
union Vec_0026C4E8 {
    qword q;
    float c[4];
    Vec_0026C4E8& operator=(const Vec_0026C4E8& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_0026C4E8 {
    Vec_0026C4E8 r[4];
};

extern "C" Mat_0026C4E8* func_00135120(void* p);

struct Obj_0026C4E8 {
    char pad[0x34];
    int m34;
    char pad2[0x40 - 0x38];
    void* m40;
    char pad3[0x50 - 0x44];
    Vec_0026C4E8 m50;
    Vec_0026C4E8 m60;
    void Attach(void* p);
};

void Obj_0026C4E8::Attach(void* p)
{
    m40 = p;
    if (p && !m34) {
        Mat_0026C4E8* m = func_00135120(p);
        m50 = m->r[0];
        m60 = m->r[1];
    }
}
