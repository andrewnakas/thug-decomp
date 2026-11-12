/* cflags: -fno-gcse */
/* fuzzy: 48.0 */
/* Vehicle component script member functions (assert path: gel/components/vehiclecomponent.cpp).
   Returns 0/1 for handled queries and commands, 2 for "not mine". */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_001948C0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
};

struct Mat_001948C0 {
    Vec_001948C0 r[4];
    /* row vector times the 3x3 part, w passed through */
    Vec_001948C0 Rotate(const Vec_001948C0& p) const
    {
        Vec_001948C0 o;
        o.x = p.x * r[0].x + p.y * r[1].x + p.z * r[2].x;
        o.y = p.x * r[0].y + p.y * r[1].y + p.z * r[2].y;
        o.z = p.x * r[0].z + p.y * r[1].z + p.z * r[2].z;
        o.w = p.w;
        return o;
    }
};

static inline Vec_001948C0 Scale(const Vec_001948C0& v, float s)
{
    Vec_001948C0 o;
    o.x = v.x * s;
    o.y = v.y * s;
    o.z = v.z * s;
    o.w = v.w * s;
    return o;
}

static inline Vec_001948C0 Neg(const Vec_001948C0& v)
{
    Vec_001948C0 o;
    o.x = -v.x;
    o.y = -v.y;
    o.z = -v.z;
    o.w = -v.w;
    return o;
}

static inline void Add(Vec_001948C0& d, const Vec_001948C0& v)
{
    d.x += v.x;
    d.y += v.y;
    d.z += v.z;
    d.w += v.w;
}

static inline void Sub(Vec_001948C0& d, const Vec_001948C0& v)
{
    d.x -= v.x;
    d.y -= v.y;
    d.z -= v.z;
    d.w -= v.w;
}

static inline float FeetToInches(float f) { return f * 12.0f; }

static inline Vec_001948C0 FeetToInches(const Vec_001948C0& v)
{
    Vec_001948C0 o;
    o.x = FeetToInches(v.x);
    o.y = FeetToInches(v.y);
    o.z = FeetToInches(v.z);
    o.w = FeetToInches(v.w);
    return o;
}

struct Model_001948C0 {
    char pad0[0x50];
    Vec_001948C0 pos;       /* 0x50 */
    char pad60[0x10];
    Mat_001948C0 matrix;    /* 0x70 */
};

struct Script_001948C0 {
    char pad0[0xB8];
    void* object;           /* 0xB8 */
};

struct Skater_001948C0 {
    char pad0[0xAC];
    unsigned int mode;      /* 0xAC */
};

struct VehicleComponent_001948C0 {
    char pad0[0xC];
    Model_001948C0* model;  /* 0x0C */
    char pad10[0x10];
    Vec_001948C0 pos;       /* 0x20 */
    Vec_001948C0 mom;       /* 0x30 */
    Vec_001948C0 orient;    /* 0x40, quaternion */
    Vec_001948C0 angMom;    /* 0x50 */
    int controlled;         /* 0x60 */
    int locked;             /* 0x64 */
    char pad68[8];
    Mat_001948C0 matrix;    /* 0x70 */
    Vec_001948C0 vel;       /* 0xB0 */
    Vec_001948C0 rotVel;    /* 0xC0 */
    Mat_001948C0 invInertia;/* 0xD0 */
    char pad110[0x120 - 0x110];
    int state;              /* 0x120 */
    char pad124[0x180 - 0x124];
    float mass;             /* 0x180 */
    char pad184[0xC];
    float inertia;          /* 0x190 */
    char pad194[0x1C4 - 0x194];
    int targetState;        /* 0x1C4 */
    char pad1C8[0x1330 - 0x1C8];
    int onGround;           /* 0x1330 */
    char pad1334[0x135C - 0x1334];
    float gravity;          /* 0x135C */
    float gravityTime;      /* 0x1360 */
    int gravityOverride;    /* 0x1364 */

    int CallMemberFunction(unsigned int name, void* params, Script_001948C0* script);
};

extern Skater_001948C0* D_00392808;
extern void* D_0038FC78;
extern char D_0038CA20[];
extern char D_0038CA28[];
extern char D_00362060[];
extern char D_0036207F[];
extern char D_003620C8[];

extern "C" void func_00103F28(const char* fmt, const char* file, int line, const char* msg);
extern "C" Vec_001948C0* func_00114E18(void* obj);
extern "C" Mat_001948C0* func_00114E48(void* obj);
extern "C" void func_00119228(Vec_001948C0* q, float w);
extern "C" void func_00119230(Vec_001948C0* q, float x, float y, float z);
extern "C" float func_0011D4C0(Vec_001948C0* q);
extern "C" void* func_0013B0E8(int i);
extern "C" void func_001953A8(VehicleComponent_001948C0* self, void* src);
extern "C" void func_00195A68(VehicleComponent_001948C0* self, Vec_001948C0* v);
extern "C" void func_00196BE0(VehicleComponent_001948C0* self);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_001948C0* out, int required);
extern "C" bool func_001E8038(void* params, void* name, Vec_001948C0* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00229668(unsigned int id, int create);
extern "C" void* func_00229DF0(void* obj);
extern "C" int func_00229EB0(void* group);
extern "C" void* func_00229F48(void* group, int i);
extern "C" void* func_0022CBF8(void* mgr, int i);
extern "C" bool func_002584E0(void* obj);

int VehicleComponent_001948C0::CallMemberFunction(unsigned int name, void* params, Script_001948C0* script)
{
    switch (name) {
    case 0x81FAAC21:
        return onGround != 0;

    case 0x279602ED:
        return state == targetState;

    case 0x5008B253:
        return gravityOverride != 0;

    case 0x4C73526B: {
        Vec_001948C0 v;
        func_001E7FA8(params, 0xA6F5352F, &v, 1);
        func_00195A68(this, &v);
        return 1;
    }

    case 0x4B0B27DD: {
        unsigned int id;
        if (func_001E8398(params, 0, &id, 0)) {
            func_001953A8(this, func_00229DF0(func_00229668(id, 1)));
            return 1;
        }
        void* group = script->object;
        int n = func_00229EB0(group);
        for (int i = 0; i < n; i++) {
            void* obj = func_00229F48(group, i);
            if (func_002584E0(obj)) {
                func_001953A8(this, func_00229DF0(obj));
                return 1;
            }
        }
        if (D_00392808->mode != 0xD443A2BC)
            func_001953A8(this, func_00229DF0(func_0022CBF8(D_0038FC78, 0)));
        return 1;
    }

    case 0x93B713A6: {
        locked = 0;
        controlled = 1;
        Vec_001948C0 impulse;
        Vec_001948C0 angImpulse;
        func_001E8038(params, D_0038CA20, &impulse, 0);
        func_001E8038(params, D_0038CA28, &angImpulse, 0);
        impulse = matrix.Rotate(impulse);
        angImpulse = matrix.Rotate(angImpulse);
        Add(mom, Scale(impulse, 1.0f / mass));
        Add(angMom, Scale(angImpulse, 1.0f / inertia));
        vel = Scale(mom, mass);
        vel.w = 0.0f;
        rotVel = invInertia.Rotate(angMom);
        return 1;
    }

    case 0xA80A0D36:
        locked = 0;
        controlled = 1;
        return 1;

    case 0xC33608E4: {
        void* obj = func_0013B0E8(0);
        if (!obj)
            return 1;
        Vec_001948C0* p = func_00114E18(obj);
        Mat_001948C0* m = func_00114E48(obj);
        pos = *p;
        Add(pos, FeetToInches(FeetToInches(m->r[1])));
        Sub(pos, FeetToInches(FeetToInches(m->r[2])));
        model->pos = pos;
        matrix.r[0] = Neg(m->r[0]);
        matrix.r[1] = m->r[1];
        matrix.r[2] = Neg(m->r[2]);

        /* matrix -> quaternion */
        Vec_001948C0 q;
        float trace = matrix.r[0].x + matrix.r[1].y + matrix.r[2].z;
        if (trace > 0.0f) {
            float s = sqrtf(trace + 1.0f);
            func_00119228(&q, s * 0.5f);
            s = 0.5f / s;
            func_00119230(&q, (matrix.r[2].y - matrix.r[1].z) * s, (matrix.r[0].z - matrix.r[2].x) * s,
                          (matrix.r[1].x - matrix.r[0].y) * s);
        } else {
            int i = 0;
            if (matrix.r[0].x < matrix.r[1].y)
                i = 1;
            if (matrix.r[i][i] < matrix.r[2].z)
                i = 2;
            int j = (i + 1) % 3;
            int k = (j + 1) % 3;
            float s = sqrtf(matrix.r[i][i] - (matrix.r[j][j] + matrix.r[k][k]) + 1.0f);
            q[i] = s * 0.5f;
            s = 0.5f / s;
            q[j] = (matrix.r[j][i] + matrix.r[i][j]) * s;
            q[k] = (matrix.r[k][i] + matrix.r[i][k]) * s;
            q.w = (matrix.r[k][j] - matrix.r[j][k]) * s;
        }
        orient = q;

        float len = sqrtf(func_0011D4C0(&orient));
        if (len > 0.0f) {
            float inv = 1.0f / len;
            orient.x *= inv;
            orient.y *= inv;
            orient.z *= inv;
            orient.w *= inv;
        }

        /* quaternion -> matrix */
        float n = orient.x * orient.x + orient.y * orient.y + orient.z * orient.z + orient.w * orient.w;
        float s = (n > 0.0f) ? 2.0f / n : 0.0f;
        float xs = orient.x * s, ys = orient.y * s, zs = orient.z * s;
        float wx = orient.w * xs, wy = orient.w * ys, wz = orient.w * zs;
        float xx = orient.x * xs, xy = orient.x * ys, xz = orient.x * zs;
        float yy = orient.y * ys, yz = orient.y * zs, zz = orient.z * zs;
        matrix.r[0].x = 1.0f - (yy + zz);
        matrix.r[0].y = xy - wz;
        matrix.r[0].z = xz + wy;
        matrix.r[1].x = xy + wz;
        matrix.r[1].y = 1.0f - (xx + zz);
        matrix.r[1].z = yz - wx;
        matrix.r[2].x = xz - wy;
        matrix.r[2].y = yz + wx;
        matrix.r[2].z = 1.0f - (xx + yy);
        matrix.r[3].x = 0.0f;
        matrix.r[3].y = 0.0f;
        matrix.r[3].z = 0.0f;
        matrix.r[3].w = 1.0f;
        model->matrix = matrix;
        func_00196BE0(this);
        return 1;
    }

    case 0xDB35AAD8:
        func_001E7EB0(params, 0x9E497FC6, &gravity, 1);
        gravity *= 0.01f;
        func_001E7EB0(params, 0x79A07F3F, &gravityTime, 1);
        func_00103F28(D_00362060, D_0036207F, 0x375, D_003620C8);
        return 1;
    }
    return 2;
}
