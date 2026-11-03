typedef int qword __attribute__((mode(TI)));
union Vec_0028F010 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct State_0028F010 { int pad; int state; unsigned int time; };
extern "C" unsigned int func_0010FC30();
static inline void SetState(State_0028F010* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
struct Sub_0028F010 {
    char pad[0x1C];
    int m1C;
    char pad1[0x84 - 0x20];
    State_0028F010 m84;
    char pad2[0xC4 - 0x90];
    int mC4;
};
struct Sk_0028F010 { char pad[0x5B0]; Sub_0028F010* m_sub; };
struct Node_0028F010 {
    char pad[0x50];
    Vec_0028F010 m50;
    Vec_0028F010 m60;
    char pad1[0xB0 - 0x70];
    Vec_0028F010 mB0;
};
struct Obj_0028F010;
extern "C" void func_0028F8F0(Obj_0028F010*);
extern "C" void func_0028F0C8(Obj_0028F010*);

struct Obj_0028F010 {
    char pad0[0xC];
    Node_0028F010* m_node;
    char pad1[0x24 - 0x10];
    Sk_0028F010* m24;
    void Update();
};

void Obj_0028F010::Update()
{
    Sub_0028F010* s = m24->m_sub;
    if (!s->m1C || m_node->mB0.f.y < 0.0f) {
        SetState(&s->m84, 1);
    }
    if (!m24->m_sub->mC4) func_0028F8F0(this);
    func_0028F0C8(this);
    m_node->m60 = m_node->m50;
}
