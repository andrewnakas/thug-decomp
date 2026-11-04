typedef int qword_00295EB0 __attribute__((mode(TI)));
struct Vec_00295EB0 {
    union {
        qword_00295EB0 q;
        struct { float x, y, z, w; } f;
    };
    Vec_00295EB0(float a, float b, float c) { f.x = a; f.y = b; f.z = c; f.w = 1.0f; }
};
struct Info_00295EB0 {
    char pad[0x40];
    Vec_00295EB0 m40;
    char pad50[0x7C - 0x50];
    float m7C;
    char pad80[0x8C - 0x80];
    float m8C;
};
struct Ent_00295EB0;
struct Obj_00295EB0 {
    char pad[0xA5C0];
    Ent_00295EB0* mA5C0;
    int padA5C4;
    Info_00295EB0* mA5C8;
    void Sync();
};

extern "C" int func_00294A68(Ent_00295EB0* e, Vec_00295EB0* v, float* a, float* b);

void Obj_00295EB0::Sync()
{
    Vec_00295EB0 v(0.0f, 0.0f, 0.0f);
    float a = v.f.x;
    float b = v.f.x;
    func_00294A68(mA5C0, &v, &a, &b);
    mA5C8->m8C = a;
    mA5C8->m7C = b;
    mA5C8->m40 = v;
}
