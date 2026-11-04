typedef int qword __attribute__((mode(TI)));
union Row_0028D770 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_0028D770 {
    Row_0028D770 r[4];
    Mat_0028D770* Self() { return this; }
};
struct V3_0028D770 { float x, y, z; };
extern "C" Mat_0028D770* func_00100928(Mat_0028D770* out, float angle);
extern "C" void func_00323318(Mat_0028D770* a, Mat_0028D770* b, Mat_0028D770* out);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);

struct Body_0028D770 {
    char pad[0x70];
    Mat_0028D770 m70;
    V3_0028D770 mB0;
};
struct Ctl_0028D770 {
    char pad[0x74];
    int m74;
    char pad78[0x98 - 0x78];
    int m98;
};

struct Obj_0028D770 {
    char pad0[0xC];
    Body_0028D770* mC;
    char pad10[0x10];
    Mat_0028D770 m20;
    char pad60[0x594 - 0x60];
    Ctl_0028D770* m594;
    void Spin();
    void Rot(Mat_0028D770* dst, float a)
    {
        Mat_0028D770 tm;
        Mat_0028D770 r;
        Mat_0028D770* src = func_00100928((Mat_0028D770*)0x70003FC0, a);
        Mat_0028D770* p = r.Self();
        *p = *src;
        func_00323318(p, dst, p);
        tm = r;
        *dst = tm;
    }
};

void Obj_0028D770::Spin()
{
    Ctl_0028D770* c = m594;
    float a;
    if (c->m74) {
        a = func_002032A0(0x38505EF3, 0) * 0.01745329425f;
    } else if (c->m98) {
        a = -(func_002032A0(0x38505EF3, 0) * 0.01745329425f);
    } else {
        return;
    }
    Body_0028D770* b = mC;
    float s = func_00341068(a);
    float co = func_00340F60(a);
    V3_0028D770* v = &b->mB0;
    float z = v->z;
    float x = v->x;
    v->x = co * x + s * z;
    v->z = -s * x + co * z;
    Rot(&mC->m70, a);
    Rot(&m20, a);
}
