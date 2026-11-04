typedef int qword __attribute__((mode(TI)));

union Vec_00280220 {
    qword q;
    struct { float x, y, z, w; } f;
};

struct State_00280220 { int pad; int state; unsigned int time; };
extern "C" unsigned int func_0010FC30();
static inline void SetState(State_00280220* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Sub_00280220 {
    char pad0[0x3C];
    State_00280220 m3C;
    State_00280220 m48;
    char pad1[0x58 - 0x54];
    int m58;
    char pad2[0x90 - 0x5C];
    State_00280220 m90;
};

struct Node_00280220 {
    char pad0[0x50];
    Vec_00280220 m50;
    Vec_00280220 m60;
    char pad1[0x90 - 0x70];
    Vec_00280220 m90;
    Vec_00280220 mA0;
    Vec_00280220 mB0;
};

struct Obj_00280220;
extern "C" void func_00279FD0(int, Vec_00280220*, Vec_00280220*);
extern "C" void func_003233B8(Vec_00280220*, Vec_00280220*);
extern "C" int func_00101730(Vec_00280220*, Vec_00280220*);
extern "C" void func_0027FDB0(Obj_00280220*, Vec_00280220*);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float sqrtf(float);

struct Obj_00280220 {
    char pad0[0xC];
    Node_00280220* m_node;
    char pad1[0x70 - 0x10];
    Vec_00280220 m70;
    char pad2[0x2F0 - 0x80];
    Vec_00280220 m2F0;
    Vec_00280220 m300;
    Vec_00280220 m310;
    float m320;
    char pad3[0x5B0 - 0x324];
    Sub_00280220* m_sub;
    void Update();
};

void Obj_00280220::Update()
{
    Sub_00280220* s = m_sub;
    if (s->m58) {
        func_00279FD0(3, &m_node->m60, &m_node->m50);
        Vec_00280220 v = m70;
        m300 = v;
        m2F0 = m_node->m60;
        m2F0.f.y -= 1.0f;
        v.f.y = 0.0f;
        if (sqrtf(v.f.x * v.f.x + v.f.z * v.f.z) > 0.001f) {
            func_003233B8(&v, &v);
            func_00101730(&m_node->mB0, &v);
            {
                Vec_00280220 c = v;
                func_0027FDB0(this, &c);
            }
            Node_00280220* n = m_node;
            Vec_00280220& d = n->m50;
            m310 = n->m90;
            m310.f.y = -m310.f.y;
            float k = func_002032A0(0x78384871, 0);
            {
            Vec_00280220 t;
            t.f.x = v.f.x * k;
            t.f.y = v.f.y * k;
            t.f.z = v.f.z * k;
            t.f.w = v.f.w * k;
            d.f.x += t.f.x; d.f.y += t.f.y; d.f.z += t.f.z; d.f.w += t.f.w;
            }
            SetState(&m_sub->m3C, 1);
            SetState(&m_sub->m48, 1);
            SetState(&m_sub->m90, 1);
            m320 = 6.0f;
        } else {
            SetState(&m_sub->m3C, 0);
        }
    } else {
        SetState(&s->m3C, 0);
    }
}
