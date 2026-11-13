/* fuzzy: 91.6 */
typedef int qword __attribute__((mode(TI)));

union Vec_0029D068 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    Vec_0029D068() {}
    Vec_0029D068(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

static inline Vec_0029D068 operator+(const Vec_0029D068& a, const Vec_0029D068& b)
{
    return Vec_0029D068(a.f.x + b.f.x, a.f.y + b.f.y, a.f.z + b.f.z, a.f.w + b.f.w);
}

static inline void Add_0029D068(Vec_0029D068* r, const Vec_0029D068& a, const Vec_0029D068& b)
{
    r->f.x = a.f.x + b.f.x;
    r->f.y = a.f.y + b.f.y;
    r->f.z = a.f.z + b.f.z;
    r->f.w = a.f.w + b.f.w;
}

static inline Vec_0029D068 operator*(const Vec_0029D068& a, float s)
{
    return Vec_0029D068(a.f.x * s, a.f.y * s, a.f.z * s, a.f.w * s);
}

static inline void operator+=(Vec_0029D068& a, const Vec_0029D068& b)
{
    a.f.x += b.f.x;
    a.f.y += b.f.y;
    a.f.z += b.f.z;
    a.f.w += b.f.w;
}

/* Cross product with w cleared. */
static inline Vec_0029D068 Cross_0029D068(const Vec_0029D068& a, const Vec_0029D068& b)
{
    return Vec_0029D068(a.f.y * b.f.z - a.f.z * b.f.y, a.f.z * b.f.x - a.f.x * b.f.z, a.f.x * b.f.y - a.f.y * b.f.x, 0.0f);
}

union Row_0029D068 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Mat_0029D068 {
    Row_0029D068 r[4];
    Mat_0029D068& operator=(const Mat_0029D068& o)
    {
        r[0].q = o.r[0].q;
        r[1].q = o.r[1].q;
        r[2].q = o.r[2].q;
        r[3].q = o.r[3].q;
        return *this;
    }
};


extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_0029D068 {
    char pad[0xA0];
    Vec_0029D068 hit;
    Vec_0029D068 normal;
    struct Ref {
        void* p;
        ~Ref()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char pad2[0xE0 - 0xC4];
};

/* Controller state: digital buttons and analog sticks. */
struct Pad_0029D068 {
    char pad0[0x8];
    int m8;
    char pad1[0x2C - 0xC];
    int m2C;
    char pad2[0x50 - 0x30];
    int m50;
    char pad3[0x74 - 0x54];
    int m74;
    char pad4[0x98 - 0x78];
    int m98;
    char pad5[0xBC - 0x9C];
    int mBC;
    char pad6[0x104 - 0xC0];
    int m104;
    char pad7[0x128 - 0x108];
    int m128;
    char pad8[0x24C - 0x12C];
    float m24C;
    float m250;
    float m254;
    float m258;
};

struct Input_0029D068 {
    char pad0[0x20];
    int flags;
    Pad_0029D068 pad;
};

struct Cam_0029D068 {
    char pad0[0x50];
    Vec_0029D068 pos;
    char pad1[0x70 - 0x60];
    Mat_0029D068 mat;
};

struct Game_0029D068 {
    char pad0[0x3B0];
    unsigned int mode;
};

struct Prefs_0029D068 {
    char pad0[0xAC];
    unsigned int layout;
};

extern int D_00388814;
extern Game_0029D068* D_0038FC78;
extern Prefs_0029D068* D_00392808;

struct Obj_0029D068;
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" void* func_00209240(Coll_0029D068* c);
extern "C" void func_00209360(Coll_0029D068* c, Vec_0029D068* a);
extern "C" void func_00209370(Coll_0029D068* c, Vec_0029D068* b);
extern "C" bool func_002093E8(Coll_0029D068* c, int a, int b);
extern "C" void func_0029C158(void* o, int v);
extern "C" void* func_0029C320();
extern "C" bool func_0029CA28(Obj_0029D068* o, Vec_0029D068* target, float up);
extern "C" void func_0029CEA0(Obj_0029D068* o);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

struct Obj_0029D068 {
    char pad0[0xC];
    Cam_0029D068* camera;
    char pad1[0x20 - 0x10];
    Vec_0029D068 target;
    Vec_0029D068 eye;
    Vec_0029D068 pos;
    Vec_0029D068 right;
    Vec_0029D068 fwd;
    float dist;
    float distMin;
    float distMax;
    float heading;
    float pitch;
    float pitchMin;
    float pitchMax;
    float height;
    float heightFloor;
    char pad2[0x9C - 0x94];
    Input_0029D068* input;
    void Update();
};

void Obj_0029D068::Update()
{
    pitchMin = func_001E5318(0x7D16D113, 0);
    pitchMax = func_001E5318(0x411BEE4A, 0);
    Pad_0029D068* pad = &input->pad;

    heading += func_001E5318(0x8242D878, 0) * pad->m254;
    while (heading > 6.2831855f)
        heading -= 6.2831855f;
    while (heading < 0.0f)
        heading += 6.2831855f;

    pitch += -func_001E5318(0x3CFA3A72, 0) * pad->m258;
    if (pitch > pitchMax)
        pitch = pitchMax;
    if (pitch < pitchMin)
        pitch = pitchMin;

    int out = 0;
    int in = 0;
    int up = 0;
    int down = 0;
    switch (D_00388814) {
    case 4: {
        int flags = input->flags;
        if (flags & 0x400000)
            in = 1;
        if (flags & 0x800000)
            out = 1;
        if (D_00392808->layout == 0x7ECA21E5) {
            if (flags & 0x1000)
                up = 1;
            if (flags & 0x4000)
                down = 1;
        } else {
            if (flags & 0x2000)
                up = 1;
            if (flags & 0x1000)
                down = 1;
        }
        break;
    }
    case 5: {
        int flags = input->flags;
        if (flags & 0x1000000) {
            if (flags & 0x2000)
                in = 1;
            if (flags & 0x1000)
                out = 1;
        } else {
            if (flags & 0x2000)
                down = 1;
            if (flags & 0x1000)
                up = 1;
        }
        break;
    }
    default:
        in = pad->m104;
        out = pad->m128;
        up = pad->m98;
        down = pad->mBC;
        break;
    }

    float zoom = func_001E5318(0x4E58F829, 0);
    if (!in) {
        if (out)
            zoom = -zoom;
        else
            zoom = 0.0f;
    }
    dist += zoom * dist;
    if (dist < distMin)
        dist = distMin;
    if (dist > distMax)
        dist = distMax;

    float t = (dist - distMin) / (distMax - distMin);
    float lo = func_001E5318(0x604961F4, 0);
    float rise = lo + t * (func_001E5318(0x5C445EAD, 0) - lo);
    if (dist < 100.0f)
        rise = 0.2f;
    if (!up) {
        if (down)
            rise = -rise;
        else
            rise = 0.0f;
    }
    height += rise;
    float maxHeight = func_001E5318(0x61D56FA0, 0);
    if (height > maxHeight)
        height = maxHeight;

    Game_0029D068* game = D_0038FC78;
    if (game->mode == 0xE8B4B836)
        func_0029C158(func_0029C320(), 0);

    Coll_0029D068 c;
    func_00209240(&c);
    func_00209360(&c, &pos);
    {
        Vec_0029D068 end;
        Vec_0029D068 off;
        off.Set(0.0f, height + 10.0f, 0.0f, 1.0f);
        Add_0029D068(&end, pos, off);
        func_00209370(&c, &end);
    }
    if (func_002093E8(&c, 1, 0))
        height = c.hit.f.y - pos.f.y - 10.0f;

    if (rise < 0.0f) {
        if (heightFloor <= height - rise + 0.01f) {
            if (height < heightFloor)
                height = heightFloor;
        }
    }
    if (height < 0.0f)
        height = 0.0f;

    right.Set(func_00340F60(heading), 0.0f, -func_00341068(heading), 1.0f);
    fwd.Set(func_00341068(heading), 0.0f, func_00340F60(heading), 1.0f);

    float lo2 = func_001E5318(0x83BDE786, 0);
    float speed = lo2 + t * (func_001E5318(0xBFB0D8DF, 0) - lo2);
    if (dist < 100.0f)
        speed = 1.0f;

    float sx = pad->m24C * 0.0078125f;
    float sz = pad->m250 * 0.0078125f;
    if (__builtin_fabsf(sx) < 0.01f) {
        if (pad->m50)
            sx = -0.5f;
        if (pad->m74)
            sx = 0.5f;
    }
    if (__builtin_fabsf(sz) < 0.01f) {
        if (pad->m8)
            sz = -0.5f;
        if (pad->m2C)
            sz = 0.5f;
    }

    Vec_0029D068 move = right * sx * speed + fwd * sz * speed;
    Vec_0029D068 old = pos;
    pos += move;
    {
        Vec_0029D068 probe = old;
        bool blocked = !func_0029CA28(this, &probe, func_001E5318(0xC7210318, 0));
        if (blocked) {
            Coll_0029D068 c2;
            func_00209240(&c2);
            func_00209360(&c2, &old);
            probe = old;
            probe.f.y += 120.0f;
            func_00209370(&c2, &probe);
            Vec_0029D068 back;
            if (func_002093E8(&c2, 1, 0)) {
                pos = old;
            } else {
                back = old;
                bool stuck = !func_0029CA28(this, &back, func_001E5318(0x56C2BFF2, 0));
                if (stuck)
                    pos = old;
                else
                    height = heightFloor;
            }
        }
    }

    if (game->mode == 0xE8B4B836)
        func_0029C158(func_0029C320(), 1);

    target.f.z = pos.f.z;
    target.f.x = pos.f.x;
    target.f.y += (pos.f.y + height - target.f.y) * func_001E5318(0x725AD02C, 0);

    Vec_0029D068 dir;
    dir.f.x = fwd.f.x * func_00340F60(pitch);
    dir.f.z = fwd.f.z * func_00340F60(pitch);
    dir.f.y = func_00341068(pitch);

    Mat_0029D068 m;
    m.r[2].q = dir.q;
    m.r[0].q = right.q;
    m.r[1].q = Cross_0029D068(dir, right).q;
    m.r[0].f.w = 0.0f;
    m.r[2].f.w = 0.0f;
    m.r[1].f.w = 0.0f;
    m.r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    camera->mat = m;

    Vec_0029D068 base = target;
    eye = base + dir * dist;
    eye.f.w = 1.0f;
    camera->pos = eye;
    func_0029CEA0(this);
}
