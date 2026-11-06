typedef int qword __attribute__((mode(TI)));

struct Vec_00168368 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00168368() {}
    Vec_00168368(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern Vec_00168368 D_003E1630;

struct Obj_00168368 {
    char pad0[0x40];
    Vec_00168368 m40;
    char pad50[0xB0 - 0x50];
    Vec_00168368 mB0;
    char padC0[0x160 - 0xC0];
    Vec_00168368 m160;
    void Fn(float h);
};

void Obj_00168368::Fn(float h)
{
    mB0 = Vec_00168368(0.0078125f, 0.0078125f, 0.0f, 0.0f);
    m160 = Vec_00168368(0.5f - (D_003E1630.x + m40.x * 0.0625f) * 0.0078125f,
                        0.5f - (D_003E1630.z + m40.z * 0.0625f) * 0.0078125f,
                        -(h + 36.0f + m40.y * 0.0625f), 0.0f);
}
