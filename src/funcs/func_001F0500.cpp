struct VEntry_001F0500 {
    short m_delta;
    short m_pad;
    int (*m_fn)(void* self);
};

struct Ref_001F0500 {
    char m_pad[0x8];
    VEntry_001F0500* m_vtbl;
};

struct Script_001F0500 {
    char m_pad0[0xBC];
    Ref_001F0500* m_BC;
    char m_padC0[0xCC - 0xC0];
    unsigned int m_active : 1;
    unsigned int m_b1 : 1;
    unsigned int m_b2 : 1;
    unsigned int m_b3 : 1;
    char m_padD0[0xD4 - 0xD0];
    int m_D4;
    void* m_D8;
    bool IsActive() const { return m_active; }
    unsigned int IsB2() const { return m_b2; }
    unsigned int IsB3() const { return m_b3; }
};

extern int D_00394128;
extern int D_0038E7E4;
extern int D_0038E7E8;
extern "C" Script_001F0500* func_001EE410(Script_001F0500* prev);
extern "C" int func_001EE620(Script_001F0500* s);
extern "C" int func_001EFDC0(Script_001F0500* s);
extern "C" void func_001F0210(int name, void* params, Ref_001F0500* obj, int flag, int extra);
extern "C" void func_001EE4D8(Script_001F0500* s, int flags);
extern "C" void func_001F03D0();

extern "C" void func_001F0500()
{
    D_00394128 = 0;
    D_0038E7E4 = 1;
    Script_001F0500* next;
    for (Script_001F0500* s = func_001EE410(0); s; s = next) {
        next = func_001EE410(s);
        while (next && !next->IsActive()) {
            next = func_001EE410(next);
        }
        if (!s->IsActive()) {
            continue;
        }
        if (s->IsB2() && func_001EE620(s)) {
            continue;
        }
        if (s->IsB3()) {
            Ref_001F0500* r = s->m_BC;
            if (r) {
                VEntry_001F0500* v = &r->m_vtbl[8];
                if (!v->m_fn((char*)r + v->m_delta)) {
                    continue;
                }
            }
        }
        if (func_001EFDC0(s)) {
            continue;
        }
        if (s->m_D4) {
            func_001F0210(s->m_D4, s->m_D8, s->m_BC, 0, 0);
        }
        if (s) {
            func_001EE4D8(s, 3);
        }
    }
    D_0038E7E4 = 0;
    if (D_0038E7E8) {
        func_001F03D0();
        D_0038E7E8 = 0;
    }
}
