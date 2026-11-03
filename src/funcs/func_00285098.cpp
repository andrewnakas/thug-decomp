typedef int qword __attribute__((mode(TI)));
union Row_00285098 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00285098 {
    Row_00285098 r[4];
};
struct V3_00285098 { float x, y, z; };
struct Body_00285098 {
    char pad[0x70];
    Mat_00285098 m70;
    V3_00285098 mB0;
};
struct Sub_00285098 {
    char pad[0xA0];
    int mA0;
    char padA4[0xC4 - 0xA4];
    int mC4;
};
extern "C" float func_002032A0(unsigned int, int);

struct Obj_00285098 {
    char pad0[0xC];
    Body_00285098* mC;
    char pad10[0x10];
    Mat_00285098 m20;
    char pad60[0x388 - 0x60];
    int m388;
    char pad38C[0x5B0 - 0x38C];
    Sub_00285098* m5B0;
    void Flip();
};

void Obj_00285098::Flip()
{
    if (m5B0->mA0) return;
    if (m5B0->mC4) return;
    if (m388) return;
    Body_00285098* b = mC;
    V3_00285098* v = &b->mB0;
    if (b->mB0.x * b->m70.r[2].f.x + b->mB0.y * b->m70.r[2].f.y + b->mB0.z * b->m70.r[2].f.z < 0.0f) {
        float sq = v->x * v->x + v->y * v->y + v->z * v->z;
        float k = func_002032A0(0x2BF71EEB, 0);
        if (k * k < sq) {
        Row_00285098 t;
        Body_00285098* b1 = mC;
        {
            float x = -b1->m70.r[2].f.x;
            float y = -b1->m70.r[2].f.y;
            float z = -b1->m70.r[2].f.z;
            float w = -b1->m70.r[2].f.w;
            t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
            b1->m70.r[2] = t;
        }
        Body_00285098* b2 = mC;
        {
            float x = -b2->m70.r[0].f.x;
            float y = -b2->m70.r[0].f.y;
            float z = -b2->m70.r[0].f.z;
            float w = -b2->m70.r[0].f.w;
            t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
            b2->m70.r[0] = t;
        }
        {
            float x = -m20.r[2].f.x;
            float y = -m20.r[2].f.y;
            float z = -m20.r[2].f.z;
            float w = -m20.r[2].f.w;
            t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
            m20.r[2] = t;
        }
        {
            float x = -m20.r[0].f.x;
            float y = -m20.r[0].f.y;
            float z = -m20.r[0].f.z;
            float w = -m20.r[0].f.w;
            t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
            m20.r[0] = t;
        }
    }
    }
}
