/* fuzzy: 51.9 */
// Camera-attached model update: places the base matrix from a tracked object, a named node or a
// look-at target, applies the orbit rotation about the pivot and a distance-based scale, optionally
// bobs the position, and pushes the result to every attached model.

typedef int qword __attribute__((mode(TI)));

struct Vec_0012A138 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_0012A138& operator+=(const Vec_0012A138& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Mat_0012A138 {
    Vec_0012A138 row[4];
    void Identity()
    {
        row[0].x = 1.0f;
        row[0].y = 0.0f;
        row[0].z = 0.0f;
        row[0].w = 0.0f;
        row[1].x = 0.0f;
        row[1].y = 1.0f;
        row[1].z = 0.0f;
        row[1].w = 0.0f;
        row[2].x = 0.0f;
        row[2].y = 0.0f;
        row[2].z = 1.0f;
        row[2].w = 0.0f;
        row[3].x = 0.0f;
        row[3].y = 0.0f;
        row[3].z = 0.0f;
        row[3].w = 1.0f;
    }
    void Translate(const Vec_0012A138& v)
    {
        row[3] += v;
    }
};

struct Model_0012A138 {
    void* m_obj;
    int m_lod;
    int m_08[2];
    Vec_0012A138 m_offset;
};

struct Orbit_0012A138 {
    char pad00[0x2C];
    float m_baseX;      // 0x15C
    float m_baseY;      // 0x160
    float m_scaleXZ;    // 0x164
    float m_scaleY;     // 0x168
};

struct Cam_0012A138 {
    char pad000[0x130];
    union {
        float m_fade;               // 0x130
        Orbit_0012A138 m_orbit;
    };
    char pad16C[0x1A0 - 0x16C];
    Model_0012A138 m_models[0x19];  // 0x1A0
    char pad4C0_[0x4C0 - 0x1A0 - 0x19 * 0x20];
    int m_modelCount;               // 0x4C0
    float m_fov;                    // 0x4C4
    float m_angle[3];               // 0x4C8
    float m_spin[3];                // 0x4D4
    Mat_0012A138 m_mat;             // 0x4E0
    Vec_0012A138 m_fixedTarget;     // 0x520
    int m_targetMode;               // 0x530
    unsigned int m_order;           // 0x534
    int m_targetId;                 // 0x538
    float m_bob;                    // 0x53C
    unsigned int m_bobPeriod;       // 0x540
    char pad544[0xC];
    Vec_0012A138 m_pivot;           // 0x550
    Vec_0012A138 m_localOffset;     // 0x560
    Vec_0012A138 m_dir;             // 0x570
    float m_dist;                   // 0x580
    int m_scaleByDist;              // 0x584
    float m_distScale;              // 0x588
    float m_maxScale;               // 0x58C
    int m_viewport;                 // 0x590
    unsigned int m_trackId;         // 0x594
    int m_598;
    unsigned int m_nodeName;        // 0x59C
    float m_pitch;                  // 0x5A0
    int m_dead;                     // 0x5A4
};

struct Tracked_0012A138 {
    char pad00[0x50];
    Vec_0012A138 m_pos;
};

struct Sound_0012A138 {
    char pad00[0xBC];
    void* m_owner;
};

extern int D_0038C608;
extern "C" Tracked_0012A138* func_00187B48(int mgr, unsigned int id);
extern "C" Vec_0012A138 func_00323298(const Mat_0012A138* m, const Vec_0012A138* v);
extern "C" Sound_0012A138* func_001F0750(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void func_00183CB8(void* ref, void** slot);
extern "C" void func_00183C98(void* ref, void** slot);
extern "C" void* func_00229668(unsigned int name, int a);
extern "C" void* func_00229DF0(void* node);
extern "C" void func_00229FF8(void* params, Vec_0012A138* out);
extern "C" float func_001239B0(Cam_0012A138* self);
extern "C" float func_001239C0(Cam_0012A138* self);
extern "C" void func_00128BF0(int viewport, Mat_0012A138* m, Vec_0012A138* dir, float x, float y, float fov);
extern "C" Tracked_0012A138* func_00184D70(int id);
extern "C" void func_003233B8(Vec_0012A138* dst, Vec_0012A138* src);
extern "C" void func_00100DC0(Mat_0012A138* m, int axis);
extern "C" Mat_0012A138 func_00100890(float angle);
extern "C" void func_00323318(Mat_0012A138* out, const Mat_0012A138* a, const Mat_0012A138* b);
extern "C" void func_0012AC20(Mat_0012A138* m, unsigned int order, float x, float y, float z);
extern "C" void* func_0013B0E8(int viewport);
extern "C" Vec_0012A138* func_00114E18(void* cam);
extern "C" unsigned int func_0010FC30();
extern "C" float func_00341068(float a);
extern "C" void func_0013D950(void* obj, int on);
extern "C" void func_0013CD08(void* obj, Mat_0012A138* m, int a, int lod);
extern "C" float sqrtf(float);

// Single VU0 macro-mode operations (the vector unit has no C++ spelling).
static inline void LoadVF4(const Vec_0012A138* p)
{
    __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p));
}

static inline void LoadVF5(const Vec_0012A138* p)
{
    __asm__ __volatile__("lqc2 $vf5, 0(%0)" : : "r"(p));
}

static inline void MulVF6()
{
    __asm__ __volatile__("vmul.xyzw $vf6, $vf4, $vf5");
}

static inline void StoreVF6(Vec_0012A138* p)
{
    __asm__ __volatile__("sqc2 $vf6, 0(%0)" : : "r"(p) : "memory");
}

// dst = a * b, component by component, on VU0
static inline void Mul_0012A138(Vec_0012A138* dst, const Vec_0012A138* a, const Vec_0012A138* b)
{
    LoadVF4(a);
    LoadVF5(b);
    MulVF6();
    StoreVF6(dst);
}

static inline void ScaleRows_0012A138(Mat_0012A138* m, const Vec_0012A138* s)
{
    Mul_0012A138(&m->row[0], s, &m->row[0]);
    Mul_0012A138(&m->row[1], s, &m->row[1]);
    Mul_0012A138(&m->row[2], s, &m->row[2]);
    Mul_0012A138(&m->row[3], s, &m->row[3]);
}

static inline Vec_0012A138 Add_0012A138(const Vec_0012A138& a, const Vec_0012A138& b)
{
    Vec_0012A138 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

extern "C" void func_0012A138(Cam_0012A138* self)
{
    if (self->m_dead || !self->m_modelCount) {
        return;
    }
    Mat_0012A138* m = &self->m_mat;
    Orbit_0012A138* orbit = &self->m_orbit;
    if (self->m_trackId) {
        Tracked_0012A138* t = func_00187B48(D_0038C608, self->m_trackId);
        if (t) {
            m->Identity();
            Vec_0012A138 off;
        off = func_00323298(m, &self->m_localOffset);
            Vec_0012A138 sum = Add_0012A138(t->m_pos, off);
            self->m_mat.row[3] = sum;
        } else {
            Sound_0012A138* s = func_001F0750(0xA66C1C31, 0, 0, 0, -1, 0, 0, 0, 0, 0);
            void** slot = &s->m_owner;
            if (s->m_owner) {
                func_00183CB8(s->m_owner, slot);
                s->m_owner = 0;
            }
            s->m_owner = self;
            if (self) {
                func_00183C98(self, slot);
            }
            self->m_dead = 1;
        }
    } else if (self->m_nodeName) {
        Vec_0012A138 pos;
        func_00229FF8(func_00229DF0(func_00229668(self->m_nodeName, 1)), &pos);
        m->Identity();
        Vec_0012A138 off;
        off = func_00323298(m, &self->m_localOffset);
        self->m_mat.row[3] = Add_0012A138(pos, off);
    } else {
        Vec_0012A138 dir;
        float d = self->m_dist;
        dir.Set(self->m_dir.x * d, self->m_dir.y * d, self->m_dir.z * d, 1.0f);
        float x = orbit->m_baseX + func_001239B0(self) * 0.5f;
        float y = orbit->m_baseY + func_001239C0(self) * 0.5f;
        func_00128BF0(self->m_viewport, m, &dir, x, y, self->m_fov);
        Vec_0012A138 target;
        switch (self->m_targetMode) {
        case 1:
            target = self->m_fixedTarget;
            break;
        case 2: {
            Tracked_0012A138* t = func_00184D70(self->m_targetId);
            if (t) {
                target = t->m_pos;
            }
            break;
        }
        }
        if (self->m_targetMode) {
            Vec_0012A138 pos = self->m_mat.row[3];
            m->Identity();
            Vec_0012A138 fwd;
            fwd.x = target.x - pos.x;
            fwd.y = target.y - pos.y;
            fwd.z = target.z - pos.z;
            fwd.w = target.w - pos.w;
            func_003233B8(&fwd, &fwd);
            m->row[0].x = fwd.z;
            self->m_mat.row[2] = fwd;
            m->row[0].w = 1.0f;
            m->row[0].y = 0.0f;
            m->row[0].z = -fwd.x;
            func_003233B8(&m->row[0], &m->row[0]);
            func_00100DC0(m, 2);
            float p = self->m_pitch;
            Mat_0012A138 r;
            r = func_00100890((p - -self->m_mat.row[2].y * p) * 0.017453294f);
            func_00323318(&r, m, &r);
            Mat_0012A138 c = r;
            *m = c;
            self->m_mat.row[3] += pos;
        }
    }

    Mat_0012A138 s;
    s.Identity();
    Vec_0012A138 v;
    v.Set(-self->m_pivot.x, -self->m_pivot.y, -self->m_pivot.z, -self->m_pivot.w);
    s.Translate(v);
    float ax = self->m_angle[0] + self->m_spin[0];
    float ay = self->m_angle[1] + self->m_spin[1];
    float az = self->m_angle[2] + self->m_spin[2];
    ax -= (float)(int)(ax * 0.15915494f) * 6.2831855f;
    ay -= (float)(int)(ay * 0.15915494f) * 6.2831855f;
    az -= (float)(int)(az * 0.15915494f) * 6.2831855f;
    self->m_angle[0] = ax;
    self->m_angle[1] = ay;
    self->m_angle[2] = az;
    func_0012AC20(&s, self->m_order, ax, ay, az);
    s.Translate(self->m_pivot);
    float d = self->m_dist;
    v.y = orbit->m_scaleY * d;
    v.z = v.x = orbit->m_scaleXZ * d;
    v.w = 1.0f;
    if (self->m_scaleByDist) {
        void* cam = func_0013B0E8(self->m_viewport);
        if (cam) {
            Vec_0012A138* cp = func_00114E18(cam);
            Vec_0012A138 dv;
            dv.x = self->m_mat.row[3].x - cp->x;
            dv.y = self->m_mat.row[3].y - cp->y;
            dv.z = self->m_mat.row[3].z - cp->z;
            dv.w = self->m_mat.row[3].w - cp->w;
            float k = sqrtf(dv.x * dv.x + dv.y * dv.y + dv.z * dv.z) * self->m_distScale;
            if (k < 1.0f) {
                k = 1.0f;
            }
            if (self->m_maxScale < k) {
                k = self->m_maxScale;
            }
            v.x *= k;
            v.y *= k;
            v.z *= k;
        }
    }
    ScaleRows_0012A138(&s, &v);
    {
        Mat_0012A138 w = s;
        func_00323318(&w, m, &w);
        Mat_0012A138 c = w;
        *m = c;
    }

    Vec_0012A138 bob;
    if (0.0f < self->m_bob) {
        unsigned int n = self->m_bobPeriod;
        float a = func_00341068((float)(int)((func_0010FC30() % n) * 2) * 3.1415927f / (float)(int)n);
        float k = self->m_bob * a;
        Vec_0012A138 b;
        b.x = self->m_mat.row[1].x * k;
        b.y = self->m_mat.row[1].y * k;
        b.z = self->m_mat.row[1].z * k;
        b.w = self->m_mat.row[1].w * k;
        bob = b;
    }
    int visible = 0.0001f <= self->m_fade;
    for (int i = 0; i < self->m_modelCount; i++) {
        Model_0012A138* md = &self->m_models[i];
        Vec_0012A138 p;
        p = func_00323298(m, &md->m_offset);
        Mat_0012A138 out = *m;
        if (0.0f < self->m_bob) {
            p += bob;
        }
        out.row[3] = p;
        func_0013D950(md->m_obj, visible);
        func_0013CD08(md->m_obj, &out, 0, md->m_lod);
    }
}
