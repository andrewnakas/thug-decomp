struct VSlot_0025F508 {
    short m_delta;
    short m_pad;
    void (*m_fn)(void*, int);
};

struct Detail_0025F508 {
    char m_pad[0xC];
    Detail_0025F508* m_next;
    Detail_0025F508* m_prev;
    VSlot_0025F508* m_vtbl;
    char m_pad18[0x34 - 0x18];
    unsigned int m_script;
    void* m_params;
};

extern char D_00375868[];

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" int func_0010FA80();
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001F0210(unsigned int name, void* params, int b, int c, int d);
extern "C" void func_001E6AE8(void* s, int in_chrg);

struct Mgr_0025F508 {
    void Remove(Detail_0025F508* d);
};

extern "C" int func_0025F0F0(Mgr_0025F508* self);
extern "C" void func_0025F248(Mgr_0025F508* self, Detail_0025F508* d);

void Mgr_0025F508::Remove(Detail_0025F508* d)
{
    unsigned int script = d->m_script;
    void* params = func_001E6978(func_001190D0(8));
    func_001E6AC8(params, d->m_params);
    if (func_0025F0F0(this) == 1)
        func_0025F248(this, d);
    VSlot_0025F508* s = &d->m_vtbl[9];
    ((void (*)(void*))s->m_fn)((char*)d + s->m_delta);
    d->m_prev->m_next = d->m_next;
    d->m_next->m_prev = d->m_prev;
    d->m_next = d;
    d->m_prev = d;
    if (d) {
        VSlot_0025F508* t = &d->m_vtbl[1];
        t->m_fn((char*)d + t->m_delta, 3);
    }
    func_00103F28(D_00375868, func_0010FA80());
    if (script)
        func_001F0210(script, params, 0, 0, 0);
    if (params)
        func_001E6AE8(params, 3);
}
