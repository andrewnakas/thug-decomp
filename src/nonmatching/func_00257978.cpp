/* cflags: -fno-schedule-insns */
/* fuzzy: 89.3 */
/* near miss: 22 words; game schedules += loads as if off/pos may alias, and stores m94 before reloading m4C */
typedef int qword __attribute__((mode(TI)));

struct Vec_00257978 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00257978& operator+=(const Vec_00257978& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
};

extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_00257978* out, int required);
extern "C" void func_001019B0(Vec_00257978* v);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

struct Src_00257978 {
    char pad[0x130];
    Vec_00257978 m130;
};

struct Dst_00257978 {
    char pad[0x40];
    float m40;
    float m44;
    float m48;
    float m4C;
    char pad50[0x20];
    Vec_00257978 m70;
    char pad80[0x10];
    int m90;
    int m94;
};

struct Obj_00257978 {
    char pad[0x130];
    Vec_00257978 m130;
    void Fn(Dst_00257978* d, void* params);
};

void Obj_00257978::Fn(Dst_00257978* d, void* params)
{
    Vec_00257978 off;
    d->m4C = 0.0f;
    Vec_00257978* pos = &d->m70;
    d->m90 = 0;
    d->m94 = 0;
    off.w = d->m4C;
    d->m70.q = m130.q;
    d->m44 = d->m4C;
    d->m48 = d->m4C;
    d->m40 = d->m4C;
    if (func_001E7FA8(params, 0xA6F5352F, &off, 0)) {
        func_001019B0(&off);
        *pos += off;
    }
    if (func_001E7EB0(params, 0xFF7EBAF6, &d->m4C, 0)) d->m4C *= 0.01745329425f;
    if (func_001E7EB0(params, 0x0AB21AF0, &d->m40, 0)) d->m40 *= 12.0f;
    if (func_001E7EB0(params, 0x7E832F08, &d->m44, 0)) d->m44 *= 12.0f;
    if (func_001E7EB0(params, 0x73E5BAD0, &d->m48, 0)) d->m48 *= 12.0f;
}
