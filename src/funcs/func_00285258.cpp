struct State_00285258 { int pad; int state; unsigned int time; };
extern "C" unsigned int func_0010FC30();
static inline void SetState(State_00285258* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
struct Sub_00285258 { char pad[0x24]; State_00285258 m24; };
struct Aux_00285258 { char pad[0x1FC]; State_00285258 m1FC; };
extern "C" void func_0026FDD0(State_00285258*);
extern "C" void func_001848F0(void*, unsigned int, int);

struct Obj_00285258 {
    char pad0[0xC];
    void* m_node;
    char pad1[0x3F0 - 0x10];
    unsigned int m3F0;
    char pad2[0x594 - 0x3F4];
    Aux_00285258* m594;
    char pad3[0x5B0 - 0x598];
    Sub_00285258* m_sub;
    int Check();
};

int Obj_00285258::Check()
{
    State_00285258* s = &m_sub->m24;
    Aux_00285258* a = m594;
    if (s->state) {
        State_00285258* t = &a->m1FC;
        if (t->state) return 0;
        m3F0 = func_0010FC30() - s->time;
        SetState(&m_sub->m24, 0);
        func_0026FDD0(t);
        func_001848F0(m_node, 0x8FFEFB28, 0);
        return 1;
    }
    return 0;
}
