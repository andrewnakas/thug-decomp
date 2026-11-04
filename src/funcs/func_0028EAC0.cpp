struct State_0028EAC0 { int pad; int state; unsigned int time; };
extern "C" unsigned int func_0010FC30();
struct Res_0028EAC0 { void* h; };
extern void* D_00388A70;
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_001848F0(void*, unsigned int, int);
static inline void Release(void** pp)
{
    if (*pp) {
        func_00183CB8(*pp, pp);
        *pp = 0;
    }
}
static inline void Free(Res_0028EAC0* r)
{
    Release(&r->h);
    func_0010A8D8(D_00388A70, r);
}
struct Holder_0028EAC0 { char pad[0x1C]; Res_0028EAC0* m1C; unsigned int m20; };
struct Sub_0028EAC0 { char pad[0xC0]; State_0028EAC0 mC0; };

struct Obj_0028EAC0 {
    char pad1[0x3C8];
    void* m3C8;
    char pad2[0x5B0 - 0x3CC];
    Sub_0028EAC0* m_sub;
    Holder_0028EAC0* m5B4;
    void Detach();
};

void Obj_0028EAC0::Detach()
{
    State_0028EAC0* s = &m_sub->mC0;
    if (!s->state) return;
    void** pp = &m3C8;
    s->state = 0;
    s->time = func_0010FC30();
    if (m3C8) {
        func_001848F0(m3C8, 0x2739B86D, 0);
        Release(pp);
        *pp = 0;
    }
    Holder_0028EAC0* hd = m5B4;
    Res_0028EAC0* r = hd->m1C;
    if (r) {
        Free(r);
        hd->m1C = 0;
        hd->m20 = func_0010FC30();
    }
}
