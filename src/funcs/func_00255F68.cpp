typedef int qword __attribute__((mode(TI)));

struct V_00255F68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00255F68;
extern "C" Mat_00255F68* func_00100890(Mat_00255F68* out, float a);
extern "C" void func_00323318(Mat_00255F68* d, Mat_00255F68* a, Mat_00255F68* b);

struct Mat_00255F68 {
    V_00255F68 r[4];
    Mat_00255F68() {}
    const V_00255F68& operator[](int i) const { return r[i]; }
    Mat_00255F68(const Mat_00255F68& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

static inline Mat_00255F68 Mul_00255F68(const Mat_00255F68& a, Mat_00255F68& b)
{
    Mat_00255F68 r(a);
    func_00323318(&r, &b, &r);
    return r;
}

struct Bone_00255F68 {
    V_00255F68 m0;
    V_00255F68 r[4];
};

extern float D_00390908;
extern char D_003753F8[];

extern "C" void* func_00256BD8(void* obj);
extern "C" Bone_00255F68* func_0013EF50(void* skel);
extern "C" int func_0013EF10(void* skel);
extern "C" void* func_00185578(void* obj, unsigned int crc);
extern "C" void* func_0019EBD0(void* c);
extern "C" float func_001E5370(char* name, int a);
extern "C" Mat_00255F68* func_0011D9E0(void* model);

struct Obj_00255F68 {
    char pad[0x170];
    float m170;
    void Spin();
};

void Obj_00255F68::Spin()
{
    Bone_00255F68* bones = func_0013EF50(func_00256BD8(this));
    void* model = func_0019EBD0(func_00185578(this, 0x222756D5));
    D_00390908 += func_001E5370(D_003753F8, 1) * m170;
    while (D_00390908 > 360.0f)
        D_00390908 -= 360.0f;
    while (D_00390908 < 0.0f)
        D_00390908 += 360.0f;
    if (func_0013EF10(func_00256BD8(this)) < 6)
        return;
    Mat_00255F68* mats = func_0011D9E0(model);
    for (int i = 0; i < func_0013EF10(func_00256BD8(this)); i++)
    {
        mats[i].r[0] = bones[i].r[0];
        mats[i].r[1] = bones[i].r[1];
        mats[i].r[2] = bones[i].r[2];
        mats[i].r[3] = bones[i].r[3];
    }
    for (int i = 2; i < 6; i++) {
        Mat_00255F68 t;
        mats[i] = Mul_00255F68(*func_00100890(&t, D_00390908 * 2.0f * 0.008726647f), mats[i]);
    }
    for (int i = 1; i < 6; i++)
        func_00323318(&mats[i], &mats[0], &mats[i]);
}
