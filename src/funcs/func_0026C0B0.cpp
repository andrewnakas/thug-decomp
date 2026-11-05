typedef int qword __attribute__((mode(TI)));

struct Vec_0026C0B0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};


struct Obj_0026C0B0 {
    char pad0[0x10];
    Vec_0026C0B0 pos;
    char pad20[0x48 - 0x20];
    int mode;
    float scale;
    char pad50[0x60 - 0x50];
    char box[0x20];
};

extern "C" void func_003233B8(Vec_0026C0B0* dst, Vec_0026C0B0* src);
extern "C" void func_00102E58(void* box, Vec_0026C0B0* p, Vec_0026C0B0* out);

Vec_0026C0B0 func_0026C0B0(Obj_0026C0B0* o, Vec_0026C0B0* p)
{
    Vec_0026C0B0 r;
    switch (o->mode) {
    case 0: {
        Vec_0026C0B0 d;
        d.x = p->x - o->pos.x;
        d.y = p->y - o->pos.y;
        d.z = p->z - o->pos.z;
        d.w = p->w - o->pos.w;
        func_003233B8(&d, &d);
        float s = o->scale;
        d.x *= s;
        d.y *= s;
        d.z *= s;
        d.w *= s;
        Vec_0026C0B0 t;
        t.x = o->pos.x + d.x;
        t.y = o->pos.y + d.y;
        t.z = o->pos.z + d.z;
        t.w = o->pos.w + d.w;
        r = t;
        break;
    }
    case 1:
        func_00102E58(o->box, p, &r);
        break;
    }
    return r;
}
