typedef int qword __attribute__((mode(TI)));

struct Vec_00259160 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" void func_003233B8(Vec_00259160* dst, Vec_00259160* src);

struct Obj_00259160 {
    char pad[0x10];
    Vec_00259160 m10;
    char pad20[0x30];
    Vec_00259160 m50;
    char pad60[0x30];
    Vec_00259160 m90;
    void Fn();
};

void Obj_00259160::Fn()
{
    Vec_00259160 d;
    d.x = m90.x - m10.x;
    d.y = m90.y - m10.y;
    d.z = m90.z - m10.z;
    d.w = m90.w - m10.w;
    m50.q = d.q;
    func_003233B8(&m50, &m50);
}
