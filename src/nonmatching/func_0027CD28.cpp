/* fuzzy: 95.8 */
extern "C" float sqrtf(float);
extern "C" int func_0010FC30();

typedef int qword __attribute__((mode(TI)));
union Vec_0027CD28 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    Vec_0027CD28() {}
    Vec_0027CD28(float a, float b, float x, float d)
    {
        c[0] = a;
        c[1] = b;
        c[2] = x;
        c[3] = d;
    }
    void Set(float a, float b, float x, float d)
    {
        c[0] = a;
        c[1] = b;
        c[2] = x;
        c[3] = d;
    }
    void operator+=(const Vec_0027CD28& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
};

inline Vec_0027CD28 operator*(const Vec_0027CD28& a, float k) { return Vec_0027CD28(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_0027CD28 operator+(const Vec_0027CD28& a, const Vec_0027CD28& b)
{
    return Vec_0027CD28(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_0027CD28 operator-(const Vec_0027CD28& a, const Vec_0027CD28& b)
{
    return Vec_0027CD28(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Mat_0027CD28 {
    Vec_0027CD28 r0;
    Vec_0027CD28 r1;
    Vec_0027CD28 r2;
    Vec_0027CD28 r3;
    const Vec_0027CD28& operator[](int i) const { return (&r0)[i]; }
};

// Time-stamped state flag.
struct Flag_0027CD28 {
    int m0;
    int m4;
    int m8;
    void Set(int v)
    {
        if (m4 != v) {
            m4 = v;
            m8 = func_0010FC30();
        }
    }
};

struct State_0027CD28 {
    char pad0[0x1C];
    int m_1C;
    char pad20[0x3C - 0x20];
    Flag_0027CD28 m3C;
    Flag_0027CD28 m48;
    char pad54[0x60 - 0x54];
    Flag_0027CD28 m60;
    char pad6C[0xA8 - 0x6C];
    Flag_0027CD28 mA8;
    Flag_0027CD28 mB4;
    char padC0[0xC4 - 0xC0];
    int m_onRail;
    char padC8[0xF0 - 0xC8];
    Flag_0027CD28 mF0;
    Flag_0027CD28 mFC;
    char pad108[0x13C - 0x108];
    int m_13C;
};

struct Mover_0027CD28 {
    char pad0[0xB0];
    Vec_0027CD28 m_vel;
};

// Link to a moving object the skater stands on, with its per-frame motion.
struct Contact_0027CD28 {
    Mover_0027CD28* m_obj;
    char pad4[0x60 - 0x4];
    Vec_0027CD28 m_delta;
    Mat_0027CD28 m_rot;
    int m_rotates;
};

extern void* D_00388A70;
extern "C" bool func_0020A760(Contact_0027CD28* c, Vec_0027CD28* pos);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00183CB8(void* p, void* ref);

struct Ground_0027CD28 {
    char pad0[0x1C];
    Contact_0027CD28* m_contact;
    int m_lostTime;
    void Drop()
    {
        func_0010A8D8(D_00388A70, m_contact);
        m_contact = 0;
        m_lostTime = func_0010FC30();
    }
    bool HasObject()
    {
        if (!m_contact)
            return false;
        if (!m_contact->m_obj) {
            Drop();
            return false;
        }
        return true;
    }
    bool StillOn(Vec_0027CD28* pos)
    {
        if (!HasObject())
            return false;
        if (func_0020A760(m_contact, pos))
            return true;
        Contact_0027CD28* c = m_contact;
        if (c) {
            if (c->m_obj) {
                func_00183CB8(c->m_obj, c);
                c->m_obj = 0;
            }
            func_0010A8D8(D_00388A70, c);
            m_contact = 0;
            m_lostTime = func_0010FC30();
        }
        return false;
    }
};

struct Body_0027CD28 {
    char pad0[0x50];
    Vec_0027CD28 m_pos;
    Vec_0027CD28 m_oldPos;
    Mat_0027CD28 m_mat;
    Vec_0027CD28 m_vel;
};

struct Trick_0027CD28 {
    char pad0[0x1C];
    unsigned int m_mode;
    char pad20[0x30 - 0x20];
    char m30[0x6C - 0x30];
    int m_6C;
    int m_70;
    char pad74[0x1B0 - 0x74];
    char m1B0[0x1EC - 0x1B0];
    int m_1EC;
    int m_1F0;
};

struct Sound_0027CD28 {
    char pad0[0x20];
    int m_20;
};

struct Game_0027CD28 {
    char pad0[0x24];
    void* m_panel;
};
extern Game_0027CD28* D_0038FC78;
extern int D_00390EF8;

// Line-of-sight query: segment start/end, result at +0x6C.
struct Ray_0027CD28 {
    Vec_0027CD28 m_start;
    Vec_0027CD28 m_end;
    char pad20[0x6C - 0x20];
    int m_6C;
};

struct Skater_0027CD28 {
    char pad0[0xC];
    Body_0027CD28* m_body;
    char pad10[0x20 - 0x10];
    Mat_0027CD28 m_mat;
    char pad60[0x70 - 0x60];
    Vec_0027CD28 m_normal;
    char pad80[0x94 - 0x80];
    float m_dt;
    char pad98[0xA0 - 0x98];
    Vec_0027CD28 m_lastPos;
    Ray_0027CD28 m_ray;
    char pad120[0x204 - 0x120];
    int m_204;
    char pad208[0x29C - 0x208];
    int m_29C;
    char pad2A0[0x2B4 - 0x2A0];
    int m_2B4;
    char pad2B8[0x36C - 0x2B8];
    int m_36C;
    char pad370[0x388 - 0x370];
    int m_388;
    char pad38C[0x3B4 - 0x38C];
    float m_3B4;
    char pad3B8[0x3C4 - 0x3B8];
    float m_3C4;
    char pad3C8[0x400 - 0x3C8];
    int m_400;
    char pad404[0x59C - 0x404];
    Sound_0027CD28* m_59C;
    void* m_5A0;
    char pad5A4[0x5AC - 0x5A4];
    Trick_0027CD28* m_trick;
    State_0027CD28* m_state;
    Ground_0027CD28* m_ground;
    void DoAirPhysics();
};

extern "C" void func_001016A8(Vec_0027CD28* v, Vec_0027CD28* n);
extern "C" void func_00101730(Vec_0027CD28* v, Vec_0027CD28* n);
extern "C" void func_001B0EB8(void* p, int a);
extern "C" void func_001B0EF0(void* p, int a);
extern "C" unsigned int func_001E53A0(unsigned int name, int a);
extern "C" float func_002032A0(unsigned int name, int def);
extern "C" void func_00260A28(void* p);
extern "C" bool func_00263BD8(void* panel, unsigned int name);
extern "C" void func_00263C18(void* panel, unsigned int text);
extern "C" bool func_0027D6B8(Skater_0027CD28* s);
extern "C" void func_0027D7D8(Skater_0027CD28* s);
extern "C" bool func_0027D9F0(Skater_0027CD28* s);
extern "C" void func_0027DAC8(Skater_0027CD28* s);
extern "C" void func_0027DC30(Skater_0027CD28* s);
extern "C" void func_0027E0C8(Skater_0027CD28* s);
extern "C" void func_0027E7A8(Skater_0027CD28* s);
extern "C" void func_0027ECE0(Skater_0027CD28* s);
extern "C" void func_0027F6B0(Skater_0027CD28* s);
extern "C" void func_00280220(Skater_0027CD28* s);
extern "C" void func_00282C88(Skater_0027CD28* s);
extern "C" void func_00282F68(Skater_0027CD28* s, Vec_0027CD28* vel);
extern "C" void func_00283050(Skater_0027CD28* s);
extern "C" void func_00284D00(Skater_0027CD28* s);
extern "C" void func_00285098(Skater_0027CD28* s);
extern "C" bool func_00285258(Skater_0027CD28* s);
extern "C" bool func_0028E1C0(Skater_0027CD28* s, int flags, int a);
extern "C" int func_003233B8(Vec_0027CD28* d, Vec_0027CD28* s);
extern "C" void func_00323318(Mat_0027CD28* dst, const Mat_0027CD28* a, const Mat_0027CD28* b);

void Skater_0027CD28::DoAirPhysics()
{
    m_state->m60.Set(0);
    m_state->m3C.Set(0);
    m_state->m48.Set(0);
    m_state->mA8.Set(0);
    m_state->mF0.Set(0);
    m_state->mB4.Set(0);
    m_state->mFC.Set(0);
    m_29C = 0;
    m_2B4 = 0;

    if (m_body->m_vel.Length() > 0.001f)
        func_00101730(&m_body->m_vel, &m_normal);

    Vec_0027CD28 gravity(0.0f, func_002032A0(0x6618A713, 0), 0.0f, 1.0f);
    if (m_3B4 != 0.0f && m_body->m_vel[1] > 0.0f) {
        // the game re-stores z here (swc1 0x8(sp) at 0027CED8)
        gravity[2] = 0.0f;
        gravity[1] = m_3C4;
    }
    func_001016A8(&gravity, &m_normal);
    m_body->m_vel += gravity * m_dt;

    switch (m_trick->m_mode) {
    case 0:
        if (func_0027D6B8(this)) {
            func_0027D7D8(this);
        } else {
            m_388 = 0;
            if (func_0027D9F0(this))
                func_0027DAC8(this);
        }
        break;
    case 0x0AC90769:
    case 0xEF24413B:
        m_388 = 0;
        func_00260A28(m_trick->m30);
        func_001B0EB8(m_5A0, 1);
        if (func_00263BD8(D_0038FC78->m_panel, 0xB38341C9)) {
            void* panel = D_0038FC78->m_panel;
            func_00263C18(panel, func_001E53A0(0xB38341C9, 0));
            m_trick->m_6C = 0;
            m_trick->m_70 = 0;
            D_00390EF8 = 1;
        }
        break;
    case 0x3506CE64:
        func_00260A28(m_trick->m1B0);
        if (func_00263BD8(D_0038FC78->m_panel, 0x69A1CE96)) {
            void* panel = D_0038FC78->m_panel;
            func_00263C18(panel, func_001E53A0(0x69A1CE96, 0));
            m_trick->m_1EC = 0;
            m_trick->m_1F0 = 0;
            D_00390EF8 = 1;
        }
        break;
    case 0xA549B57B:
        break;
    }

    func_0027DC30(this);
    func_0027E0C8(this);
    Body_0027CD28* body = m_body;
    Vec_0027CD28 step = body->m_vel * m_dt;

    if (m_state->m_onRail) {
        Contact_0027CD28* c = m_ground->m_contact;
        if (c) {
            Mover_0027CD28* obj = c->m_obj;
            if (obj)
                body->m_vel = obj->m_vel * func_002032A0(0xDEF25B34, 0);
        }
        step.Set(0.0f, 0.0f, 0.0f, 1.0f);
        func_0027E7A8(this);
    }

    // Is the skater still standing on a moving object?
    Ground_0027CD28* ground = m_ground;
    Vec_0027CD28* pos = &m_body->m_pos;
    if (ground->StillOn(pos) && !m_state->m_onRail) {
        Contact_0027CD28* c = m_ground->m_contact;
        m_body->m_pos += c->m_delta;
        m_body->m_oldPos = m_body->m_pos;
        m_lastPos = m_body->m_pos;
        c = m_ground->m_contact;
        if (c->m_rotates) {
            func_00323318(&m_body->m_mat, &c->m_rot, &m_body->m_mat);
            func_00323318(&m_mat, &m_ground->m_contact->m_rot, &m_mat);
        }
    }

    // Move; if we were blocked early, retry once with the remaining distance.
    int retried = 0;
    int again;
    do {
        again = 0;
        Body_0027CD28* bd = m_body;
        Vec_0027CD28 start = bd->m_pos;
        bd->m_pos += step;
        if (!m_state->m_onRail)
            func_0027ECE0(this);
        if (m_state->m_onRail) {
            Body_0027CD28* b = m_body;
            Ray_0027CD28& ray = m_ray;
            ray.m_start = b->m_pos + b->m_mat[1] * 36.0f;
            ray.m_end = b->m_pos - b->m_mat[1] * 200.0f;
            if (func_0028E1C0(this, 0x10, 0))
                m_59C->m_20 = m_state->m_13C = ray.m_6C;
        } else {
            func_0027F6B0(this);
        }
        Vec_0027CD28 moved;
        moved = m_body->m_pos - start;
        float want = step.Length();
        float got = moved.Length();
        if (!retried && !m_state->m_1C && got < want - 0.1f) {
            again = 1;
            retried = 1;
            step = m_body->m_vel;
            func_003233B8(&step, &step);
            step *= want;
            step *= 1.0f - got / want;
        }
    } while (again);

    if (m_state->m_1C)
        return;
    func_00282C88(this);
    if (!m_400)
        func_00282F68(this, &m_body->m_vel);
    if (!m_state->m_onRail) {
        func_00283050(this);
        func_00284D00(this);
    }
    if (!m_400)
        func_00285098(this);
    if (func_00285258(this)) {
        func_00280220(this);
        m_state->m60.Set(1);
    }
    func_001B0EF0(m_5A0, m_204);
    m_36C = 0;
}
