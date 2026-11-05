typedef int qword __attribute__((mode(TI)));

struct Vec_00295AF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Cam_00295AF0 {
    char pad0[0x40];
    Vec_00295AF0 m40;
    char pad50[0x7C - 0x50];
    float m7C;
    char pad80[0xC];
    float m8C;
};

struct Obj_00295AF0 {
    char pad0[0xA5C8];
    Cam_00295AF0* mA5C8;
    void Get(Vec_00295AF0* pos, float* a, float* b);
};

void Obj_00295AF0::Get(Vec_00295AF0* pos, float* a, float* b)
{
    *pos = mA5C8->m40;
    *a = mA5C8->m8C;
    *b = mA5C8->m7C;
}
