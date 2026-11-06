typedef int qword __attribute__((mode(TI)));

struct Vec_0013EF90 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

class Mesh_0013EF90 {
public:
    char pad0[0x1A0];
    Vec_0013EF90 m1A0;
    union {
        struct {
            unsigned long b0 : 1;
            unsigned long b1 : 1;
            unsigned long b2 : 1;
            unsigned long b3 : 1;
            unsigned long b4 : 1;
            unsigned long b5 : 1;
            short m1B2;
            int m1B4;
        };
        unsigned int m1B0;
    };
    virtual ~Mesh_0013EF90();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual Vec_0013EF90 V11();
    Vec_0013EF90 GetCenter();
};

Vec_0013EF90 Mesh_0013EF90::GetCenter()
{
    if (m1B0 & 1)
        return m1A0;
    Vec_0013EF90 v = V11();
    b0 = 1;
    m1A0 = v;
    return v;
}
