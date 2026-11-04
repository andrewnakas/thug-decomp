typedef int qword __attribute__((mode(TI)));
union Vec_00267270 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00267270 {
    Vec_00267270 r[4];
    Mat_00267270* Self() { return this; }
    inline void Mul(Mat_00267270& o);
};
extern "C" Mat_00267270* func_00100890(Mat_00267270* out, float a);
extern "C" Mat_00267270* func_001009C0(Mat_00267270* out, float a);
extern "C" void func_00323318(Mat_00267270* a, Mat_00267270* b, Mat_00267270* out);

struct Bone_00267270 {
    unsigned int m0;
    int m4;
    short m8;
    signed char mA;
    char padB[5];
    Mat_00267270 m10;
};

extern "C" Bone_00267270* func_0013EF50(void* p);
extern "C" Mat_00267270* func_0011D9E0(void* s);
extern "C" int func_0011D9E8(void* s);

inline void Mat_00267270::Mul(Mat_00267270& o) { func_00323318(this, &o, this); }

static inline void Apply_00267270(Mat_00267270* dst, Mat_00267270* src)
{
    Mat_00267270 tm;
    Mat_00267270 r;
    Mat_00267270* p = r.Self();
    *p = *src;
    func_00323318(p, dst, p);
    tm = r;
    *dst = tm;
}

extern "C" void func_00267270(void* skel, void* data, float rz, float rx, float ry)
{
    Mat_00267270 out;
    int i = 0;
    Bone_00267270* bones = func_0013EF50(data);
    Mat_00267270* mats = func_0011D9E0(skel);
    Bone_00267270* b = bones;
    rz *= 0.01745329425f;
    ry *= 0.01745329425f;
    rx *= 0.01745329425f;
    for (; i < func_0011D9E8(skel); b++, i++) {
        Mat_00267270* m = &mats[b->mA];
        *m = b->m10;
        switch (b->m0) {
        case 0x6E2F434E:
        case 0xF72612F4:
            Apply_00267270(m, func_001009C0(&out, ry));
            Apply_00267270(m, func_00100890(&out, rx));
            break;
        case 0x80212262:
        case 0x1E45B7C1:
            Apply_00267270(m, func_00100890(&out, rx));
            break;
        case 0x69428757:
        case 0xF04BD6ED:
            Apply_00267270(m, func_00100890(&out, rx));
            break;
        case 0x88C21962:
            Apply_00267270(m, func_00100890(&out, rz));
            break;
        case 0x92E19120:
            break;
        }
        if (i) m->Mul(mats[b->m8]);
    }
}
