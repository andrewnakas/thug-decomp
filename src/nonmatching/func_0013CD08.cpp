/* fuzzy: 74.9 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0013CD08 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0013CD08() {}
    Vec_0013CD08(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_0013CD08& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

struct Mat_0013CD08 {
    Vec_0013CD08 row[4];
};

struct Obj_0013CD08 {
    int m0;
    int m4;
    char pad8[0xE0];
    unsigned int mE8;
    char padEC[4];
    float mF0;
    float mF4;
    float mF8;
    char padFC[0x1B0 - 0xFC];
    unsigned long m1B0;
    int Flag(int n) const { return (int)(m1B0 >> n) & 1; }
};

extern "C" int func_0013E9D8(Obj_0013CD08* o);
extern "C" void* func_0013E9B8(Obj_0013CD08* o, int i);
extern "C" void func_0013C568(void* c, int vis);
extern "C" void func_0013C740(void* c, Mat_0013CD08* m, int a, int b);
extern "C" int func_0011D9E0(void* v);
extern "C" int func_0011D9E8(void* v);
extern "C" void func_0011D9F0(void* v, Mat_0013CD08* m, float a, float b, float c);
extern "C" void func_00123610(Mat_0013CD08* m, Vec_0013CD08* pos, Vec_0013CD08* a, int b, int c, int d,
                              unsigned int color, Vec_0013CD08* e);

static inline void Swap_0013CD08(Vec_0013CD08& a, Vec_0013CD08& b)
{
    Vec_0013CD08 t = a;
    a = b;
    b = t;
}

extern "C" bool func_0013CD08(Obj_0013CD08* self, Mat_0013CD08* m, int simple, void* view)
{
    bool noType = self->m4 == 0;
    int n = func_0013E9D8(self);
    for (int i = 0; i < n; i++) {
        void* c = func_0013E9B8(self, i);
        int vis = 0;
        if (noType && self->Flag(1)) {
            int mask = 1 << i;
            if (self->mE8 & mask)
                vis = 1;
        }
        func_0013C568(c, vis);
    }
    if (self->Flag(3)) {
        m->row[0] *= self->mF0;
        m->row[1] *= self->mF4;
        m->row[2] *= self->mF8;
    }
    switch (self->m4) {
    case 0:
        if (view) {
            m->row[0].w = 0.0f;
            m->row[1].w = 0.0f;
            m->row[2].w = 0.0f;
            m->row[3].w = 1.0f;
            int cnt = func_0013E9D8(self);
            if (simple) {
                for (int i = 0; i < cnt; i++)
                    func_0013C740(func_0013E9B8(self, i), m, 0, 0);
            } else {
                for (int i = 0; i < cnt; i++) {
                    void* c = func_0013E9B8(self, i);
                    int a = func_0011D9E0(view);
                    func_0013C740(c, m, a, func_0011D9E8(view));
                }
            }
        } else {
            m->row[0].w = 0.0f;
            m->row[1].w = 0.0f;
            m->row[2].w = 0.0f;
            m->row[3].w = 1.0f;
            int cnt = func_0013E9D8(self);
            for (int i = 0; i < cnt; i++)
                func_0013C740(func_0013E9B8(self, i), m, 0, 0);
        }
        break;
    case 1:
        if (view)
            func_0011D9F0(view, m, 0.5f, 0.5f, 1.0f);
        break;
    case 2:
    case 3:
    case 4:
    case 6:
        break;
    case 5:
    default: {
        Mat_0013CD08 t = *m;
        Vec_0013CD08 pos = t.row[3];
        t.row[3] = Vec_0013CD08(0.0f, 0.0f, 0.0f, 1.0f);
        Vec_0013CD08 hi(10.0f, 10.0f, 10.0f, 1.0f);
        Vec_0013CD08 lo(-10.0f, -10.0f, -10.0f, 1.0f);
        func_00123610(&t, &pos, &hi, 0, 1, 0, 0xFF0000C8, &lo);
        break;
    }
    }
    return true;
}
