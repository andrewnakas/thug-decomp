struct State_0028E830 { int pad; int state; unsigned int time; };
extern "C" unsigned int func_0010FC30();
static inline void SetState(State_0028E830* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
struct Res_0028E830 { void* h; };
extern void* D_00388A70;
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" Res_0028E830* func_0020A6C0(void*, void*);
extern "C" void func_001848F0(void*, unsigned int, int);
static inline void Free(Res_0028E830* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}
struct Holder_0028E830 { char pad[0x1C]; Res_0028E830* m1C; unsigned int m20; };
struct Sub_0028E830 { char pad[0xC0]; State_0028E830 mC0; };

struct Obj_0028E830;
extern "C" void func_0027E7A8(Obj_0028E830*);
struct Obj_0028E830 {
    char pad0[0x2C0];
    int m2C0;
    char pad1[0x3C8 - 0x2C4];
    void* m3C8;
    char pad2[0x5B0 - 0x3CC];
    Sub_0028E830* m_sub;
    Holder_0028E830* m5B4;
    void Attach();
};

void Obj_0028E830::Attach()
{
    void* h = m3C8;
    if (!h) return;
    Holder_0028E830* hd = m5B4;
    Res_0028E830* r = hd->m1C;
    if (r) {
        Free(r);
        hd->m1C = 0;
        hd->m20 = func_0010FC30();
    }
    hd->m1C = func_0020A6C0(func_0010A638(D_00388A70, 0xC0, 1, 0), h);
    SetState(&m_sub->mC0, 1);
    m2C0 = 1;
    func_0027E7A8(this);
    if (m3C8) func_001848F0(m3C8, 0x35224F25, 0);
}
