typedef int qword __attribute__((mode(TI)));

struct Vec_0018E138 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_0018E138() {}
    Vec_0018E138(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void operator+=(const Vec_0018E138& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
    }
};

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_0018E138(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_0018E138 {
    Vec_0018E138 m_start;
    Vec_0018E138 m_end;
    char pad20[0xC0 - 0x20];
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_0018E138()
    {
        Release_0018E138(&m_ref);
    }
};

struct Body_0018E138 {
    char pad0[0x50];
    Vec_0018E138 m_pos;
    char pad60[0x80 - 0x60];
    Vec_0018E138 m_vel;
};

struct Obj_0018E138 {
    char pad0[0x260];
    void* m_scene;
};

extern "C" void func_00209240(Feeler_0018E138* f);
extern "C" int func_002093E8(Feeler_0018E138* f, int a, int b);
extern "C" bool func_002095C8(Feeler_0018E138* f);
extern "C" float func_00209608(Feeler_0018E138* f);
extern "C" void* func_0013D8A8(void* scene);
extern "C" void func_00137BE8(void* o, float f);

class Comp_0018E138 {
public:
    char pad0[0xC];
    Body_0018E138* m_body;
    char pad10[0x1C - 0x10];
    Obj_0018E138* m_obj;

    void Probe();
};

void Comp_0018E138::Probe()
{
    Feeler_0018E138 f;
    func_00209240(&f);
    f.m_start = m_body->m_pos;
    f.m_end = m_body->m_pos;
    Body_0018E138* b = m_body;
    Vec_0018E138 d(b->m_vel.x * 0.001f, b->m_vel.y * 0.001f, b->m_vel.z * 0.001f, b->m_vel.w * 0.001f);
    f.m_start += d;
    f.m_start.y += 8.0f;
    f.m_end.y -= 4800.0f;
    if (func_002093E8(&f, 1, 0) && func_002095C8(&f)) {
        void* o = func_0013D8A8(m_obj->m_scene);
        if (o) {
            func_00137BE8(o, func_00209608(&f));
        }
    }
}
