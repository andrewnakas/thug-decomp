typedef int qword __attribute__((mode(TI)));
union Vec_0029B108 {
    qword q;
    struct { float x, y, z, w; } f;
};

struct Body_0029B108 {
    char pad[0x40];
    Vec_0029B108 m40;
    char pad50[0x7C - 0x50];
    float m7C;
    char pad80[0x8C - 0x80];
    float m8C;
};

struct Obj_0029B108 {
    char pad[0x20];
    Body_0029B108* m20;
    void Get(Vec_0029B108* pos, float* a, float* b);
};

void Obj_0029B108::Get(Vec_0029B108* pos, float* a, float* b)
{
    *pos = m20->m40;
    *a = m20->m8C;
    *b = m20->m7C;
}
