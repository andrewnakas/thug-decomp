typedef int qword_001A8210 __attribute__((mode(TI)));

struct Row_001A8210 {
    union {
        struct { float x, y, z, w; };
        qword_001A8210 q;
    };
};

struct Mat_001A8210 {
    Row_001A8210 r[4];
    void RotX(float a);
    void RotY(float a);
    void RotZ(float a);
    void Ident()
    {
        r[0].x = 1.0f;
        r[0].y = 0.0f;
        r[0].z = 0.0f;
        r[0].w = 0.0f;
        r[1].x = 0.0f;
        r[1].y = 1.0f;
        r[1].z = 0.0f;
        r[1].w = 0.0f;
        r[2].x = 0.0f;
        r[2].y = 0.0f;
        r[2].z = 1.0f;
        r[2].w = 0.0f;
        r[3].x = 0.0f;
        r[3].y = 0.0f;
        r[3].z = 0.0f;
        r[3].w = 1.0f;
    }
};

extern "C" void func_0022A268(void* node, Row_001A8210* out);
extern "C" Mat_001A8210* func_00100890(Mat_001A8210* m, float a);
extern "C" Mat_001A8210* func_00100928(Mat_001A8210* m, float a);
extern "C" Mat_001A8210* func_001009C0(Mat_001A8210* m, float a);
extern "C" Mat_001A8210* func_00323318(Mat_001A8210* dst, const Mat_001A8210* a, const Mat_001A8210* b);

inline void Mat_001A8210::RotX(float a)
{
    Mat_001A8210 tmp;
    func_00323318(this, func_00100890(&tmp, a), this);
}

inline void Mat_001A8210::RotY(float a)
{
    Mat_001A8210 tmp;
    func_00323318(this, func_00100928(&tmp, a), this);
}

inline void Mat_001A8210::RotZ(float a)
{
    Mat_001A8210 tmp;
    func_00323318(this, func_001009C0(&tmp, a), this);
}

struct Model_001A8210 {
    char pad[0x70];
    Mat_001A8210 m70;
    char padB0[0x10];
    Mat_001A8210 mC0;
};

struct Obj_001A8210 {
    char pad[0xC];
    Model_001A8210* mC;
    void Method(void* node);
};

void Obj_001A8210::Method(void* node)
{
    mC->m70.Ident();
    Row_001A8210 ang;
    func_0022A268(node, &ang);
    if (ang.x != 0.0f || ang.y != 0.0f || ang.z != 0.0f) {
        mC->m70.RotX(ang.x);
        mC->m70.RotY(ang.y);
        mC->m70.RotZ(ang.z);
    }
    Model_001A8210* m = mC;
    Mat_001A8210* d = &m->mC0;
    *d = m->m70;
}
