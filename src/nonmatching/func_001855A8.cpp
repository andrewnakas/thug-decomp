/* fuzzy: 72.1 */
/* Model/motion component script member functions: position, orientation, velocity queries, plus the
   "ask every sub-component, then the base class" fallback. */
extern float D_00387710; /* deg->rad, the game loads its .lit4 constants in a different order than the literals would compile */
extern float D_00387714;
extern float D_00387718;
extern float D_0038771C;
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_001855A8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001855A8() {}
    Vec_001855A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    Vec_001855A8& operator+=(const Vec_001855A8& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
        return *this;
    }
};

static inline Vec_001855A8 operator*(const Vec_001855A8& v, float s)
{
    return Vec_001855A8(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_001855A8 operator-(const Vec_001855A8& a, const Vec_001855A8& b)
{
    return Vec_001855A8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001855A8 operator+(const Vec_001855A8& a, const Vec_001855A8& b)
{
    return Vec_001855A8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Mat_001855A8 {
    Vec_001855A8 right;
    Vec_001855A8 up;
    Vec_001855A8 at;
    Vec_001855A8 trans;
    Mat_001855A8& operator=(const Mat_001855A8& m)
    {
        right = m.right;
        up = m.up;
        at = m.at;
        trans = m.trans;
        return *this;
    }
};

static inline void Cross(Vec_001855A8& d, const Vec_001855A8& a, const Vec_001855A8& b)
{
    Vec_001855A8 t;
    t.x = a.y * b.z - a.z * b.y;
    t.y = a.z * b.x - a.x * b.z;
    t.z = a.x * b.y - a.y * b.x;
    t.w = 0.0f;
    d = t;
}

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_001855A8 {
    Vec_001855A8 start;
    Vec_001855A8 end;
    char pad20[0xC0 - 0x20];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
    ~Coll_001855A8() { mC0.Release(); }
};

struct Script_001855A8 {
    char pad0[0x18];
    void* params;   /* 0x18, the script's return-value structure */
};

/* sub-components chained off the object; vptr at 0x18 (base fields 0x00-0x17) */
struct SubComponent_001855A8 {
    char pad0[0x10];
    SubComponent_001855A8* next;    /* 0x10 */
    int pad14;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual int CallMemberFunction(unsigned int name, void* params, Script_001855A8* script);
};

struct ModelComponent_001855A8 {
    char pad0[0x50];
    Vec_001855A8 pos;                   /* 0x50 */
    char pad60[0x10];
    Mat_001855A8 matrix;                /* 0x70 */
    Vec_001855A8 vel;                   /* 0xB0 */
    Mat_001855A8 displayMatrix;         /* 0xC0 */
    SubComponent_001855A8* subs;        /* 0x100 */
    unsigned int flags;                 /* 0x104 */

    void SetMatrix(const Mat_001855A8& m)
    {
        matrix = m;
        displayMatrix = m;
    }
    int CallMemberFunction(unsigned int name, void* params, Script_001855A8* script);
};

extern char D_0038C588[];
extern char D_0038C590[];
extern char D_0038C598[];
extern char D_0038C5A0[];
extern char D_00361A38[];

extern "C" float func_00100118(float x);    /* acos */
extern "C" void func_00100200(Mat_001855A8* m, float x, float y, float z);
extern "C" int func_001842E0(ModelComponent_001855A8* self, unsigned int name, void* params, Script_001855A8* script);
extern "C" ModelComponent_001855A8* func_00184D70(unsigned int id);
extern "C" void func_00185058(ModelComponent_001855A8* self);
extern "C" void func_00185128(ModelComponent_001855A8* self, int on);
extern "C" void func_001851B0(ModelComponent_001855A8* self, int on);
extern "C" void func_00185300(ModelComponent_001855A8* self, void* params, int a);
extern "C" void func_001E72B0(void* params, unsigned int name, float v);
extern "C" void func_001E7318(void* params, const char* name, float v);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_001855A8* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8870(void* params, unsigned int name, void* out, int required);
extern "C" void func_00209240(Coll_001855A8* c);
extern "C" bool func_002093E8(Coll_001855A8* c, int a, int b);
extern "C" void* func_00229668(unsigned int id, int create);
extern "C" void func_0022A090(void* obj, Vec_001855A8* out);
extern "C" void func_003233B8(Vec_001855A8* out, Vec_001855A8* in);    /* normalise */

int ModelComponent_001855A8::CallMemberFunction(unsigned int name, void* params, Script_001855A8* script)
{
    switch (name) {
    case 0xC2404947: {
        int tmp;
        func_001E8870(params, 0, &tmp, 0);
        return 1;
    }

    case 0x406998A5:
        func_00185300(this, params, 0);
        return 1;

    case 0xE90AAD2D:
        func_001E7410(script->params, 0x7F261953, pos.x, pos.y, pos.z);
        return 1;

    case 0xF7251A64:
        func_001E7FA8(params, 0xB9D31B0A, &pos, 0);
        return 1;

    case 0xC6F3BAA5: {
        Vec_001855A8 dir;
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = 1.0f;
        dir.w = 1.0f;
        Mat_001855A8 m;
        if (func_001E7FA8(params, 0x455485EF, &dir, 0)) {
            /* build an orthonormal frame looking along dir */
            m.right.x = 1.0f; m.right.y = 0.0f; m.right.z = 0.0f; m.right.w = 0.0f;
            m.up.x = 0.0f; m.up.y = 1.0f; m.up.z = 0.0f; m.up.w = 0.0f;
            m.at.x = 0.0f; m.at.y = 0.0f; m.at.z = 1.0f; m.at.w = 0.0f;
            m.trans.x = 0.0f; m.trans.y = 0.0f; m.trans.z = 0.0f; m.trans.w = 1.0f;
            m.at = dir;
            func_003233B8(&m.at, &m.at);
            Cross(m.right, m.up, m.at);
            func_003233B8(&m.right, &m.right);
            Cross(m.up, m.at, m.right);
            func_003233B8(&m.up, &m.up);
            SetMatrix(m);
        } else {
            float rx = 0.0f, ry = 0.0f, rz = 0.0f;
            func_001E7EB0(params, 0x7323E97C, &rx, 0);
            func_001E7EB0(params, 0x0424D9EA, &ry, 0);
            func_001E7EB0(params, 0x9D2D8850, &rz, 0);
            rx *= D_00387710;
            ry *= D_00387710;
            rz *= D_00387710;
            func_00100200(&m, rx, ry, rz);
            SetMatrix(m);
        }
        return 1;
    }

    case 0xC1BFF0F3:
        func_00185058(this);
        return 1;

    case 0x11FE9F71:
        func_001E7410(script->params, 0x0C4C809E, vel.x, vel.y, vel.z);
        return 1;

    case 0xC0CAAC4A:
        func_001E72B0(script->params, 0xF0D90109, vel.Length());
        return 1;

    case 0x5B6634D4:
        func_00185128(this, 1);
        return 1;

    case 0xB60D1F35:
        func_00185128(this, 0);
        return 1;

    case 0xB16619AE:
        if (flags & 4)
            return 1;
        return 0;

    case 0x10C1C887: {
        float d = 0.0f;
        func_001E7EB0(params, 0x7323E97C, &d, 0);
        pos += matrix.right * d;
        d = 0.0f;
        func_001E7EB0(params, 0x0424D9EA, &d, 0);
        pos += matrix.up * d;
        d = 0.0f;
        func_001E7EB0(params, 0x9D2D8850, &d, 0);
        pos += matrix.at * d;
        return 1;
    }

    case 0xCA3C59A6:
        func_001851B0(this, 0);
        return 1;

    case 0xCE0CA665:
        func_001851B0(this, 1);
        return 1;

    case 0x28656D12:
        flags |= 1;
        return 1;

    case 0xFF85D4D7:
        flags &= ~1;
        return 1;

    case 0x0168B09C: {
        /* is there collision in front of (or behind) the object? */
        Coll_001855A8 col;
        func_00209240(&col);
        float dist = 3.0f;
        func_001E7EB0(params, 0xFE82614D, &dist, 0);
        dist *= 12.0f;
        float height = 3.0f;
        func_001E7EB0(params, 0x0AB21AF0, &height, 0);
        height *= 12.0f;
        Vec_001855A8 p = pos + matrix.up * height;
        col.end = p;
        col.start = p;
        Vec_001855A8* dir = func_001E8708(params, 0xDC7EE44A) ? &matrix.right : &matrix.at;
        col.end += *dir * dist;
        if (func_002093E8(&col, 1, 0))
            return 1;
        return 0;
    }

    case 0xB9ED09D2: {
        Vec_001855A8 v = displayMatrix.at;
        func_003233B8(&v, &v);
        func_001E7318(script->params, D_0038C588, v.x);
        func_001E7318(script->params, D_0038C590, v.y);
        func_001E7318(script->params, D_0038C598, v.z);
        return 1;
    }

    case 0xD96C0A20: {
        unsigned int id = 0;
        func_001E8398(params, 0, &id, 0);
        Vec_001855A8 p;
        func_0022A090(func_00229668(id, 1), &p);
        Vec_001855A8 d;
        d.x = pos.x - p.x;
        d.y = pos.y - p.y;
        d.z = pos.z - p.z;
        d.w = pos.w - p.w;
        func_001E7318(script->params, D_0038C5A0, d.Length());
        return 1;
    }

    case 0x4AF57BBB: {
        unsigned int id = 0;
        func_001E8398(params, 0, &id, 0);
        ModelComponent_001855A8* other = func_00184D70(id);
        float feet = 0.0f;
        if (other) {
            Vec_001855A8 d;
            d.x = pos.x - other->pos.x;
            d.y = pos.y - other->pos.y;
            d.z = pos.z - other->pos.z;
            d.w = pos.w - other->pos.w;
            feet = d.Length() * D_00387714;
        }
        func_001E7318(script->params, D_00361A38, feet);
        return 1;
    }

    case 0x2A26FFA2: {
        unsigned int id = 0;
        float dot = 0.0f;
        float angle = 0.0f;
        func_001E8398(params, 0, &id, 1);
        ModelComponent_001855A8* other = func_00184D70(id);
        if (other) {
            Vec_001855A8 fwd = matrix.right;
            fwd.w = 0.0f;
            func_003233B8(&fwd, &fwd);
            Vec_001855A8 to;
            to = other->pos - pos;
            to.w = 0.0f;
            func_003233B8(&to, &to);
            dot = fwd.x * to.x + fwd.y * to.y + fwd.z * to.z;
            angle = func_00100118(dot) * D_00387718 - 90.0f;
        }
        func_001E72B0(script->params, 0x7C6A7D7C, dot);
        func_001E72B0(script->params, 0xC97F3AA9, angle);
        return 1;
    }

    case 0xF8CFD515:
        return vel.x * matrix.at.x + vel.y * matrix.at.y + vel.z * matrix.at.z < 0.0f;

    case 0x7DCC5FB9: {
        float speed = 0.0f;
        func_001E7EB0(params, 0, &speed, 0);
        return fabsf(vel.Length() - speed) < D_0038771C;
    }

    case 0xE5DF66D7: {
        float speed = 0.0f;
        func_001E7EB0(params, 0, &speed, 0);
        return speed < vel.Length();
    }

    case 0xDD468509: {
        float speed = 0.0f;
        func_001E7EB0(params, 0, &speed, 0);
        return vel.Length() < speed;
    }
    }

    for (SubComponent_001855A8* c = subs; c; c = c->next) {
        switch (c->CallMemberFunction(name, params, script)) {
        case 1:
            return 1;
        case 0:
            return 0;
        }
    }
    return func_001842E0(this, name, params, script);
}
