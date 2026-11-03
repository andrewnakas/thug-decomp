typedef int qword __attribute__((mode(TI)));
union Vec_002932E8 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Glob_002932E8 { char pad[0x3B0]; unsigned int m3B0; };
extern Glob_002932E8* D_0038FC78;
extern "C" int func_002CADB8(Vec_002932E8*, float);

struct Obj_002932E8;
extern "C" int func_00293190(Obj_002932E8*, Vec_002932E8*);

struct Obj_002932E8 {
    int Clear(Vec_002932E8* p, float off);
};

int Obj_002932E8::Clear(Vec_002932E8* p, float off)
{
    if (D_0038FC78->m3B0 == 0xE8B4B836) {
        Vec_002932E8 v = *p;
        int r = func_002CADB8(&v, 30.0f) ^ 1;
        if (r) return 0;
    }
    Vec_002932E8 v = *p;
    v.f.y += off;
    return func_00293190(this, &v) == 0;
}
