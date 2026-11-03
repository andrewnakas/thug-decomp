typedef int qword __attribute__((mode(TI)));

union Vec_00285308 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    float& operator[](int i) { return (&f.x)[i]; }
};

struct Body_00285308 {
    char pad0[0x50];
    Vec_00285308 pos;
};

struct Cand_00285308 {
    char pad0[0xC];
    Body_00285308* mC;
    int m10;
    Cand_00285308* m14;
    char pad18[4];
    int m1C;
};

struct State_00285308 {
    char pad0[0x1C];
    int m1C;
    char pad20[0xC4 - 0x20];
    int mC4;
};

struct Tm_00285308 {
    int m0;
    int m4;
};

struct Ctl_00285308 {
    char pad0[0x24];
    char m24[4];
    Tm_00285308 m28;
};

extern void* D_0038C608;
extern "C" unsigned int func_0026FDA0(Tm_00285308* t);
extern "C" unsigned int func_00203300(unsigned int id, int v);
extern "C" float func_002032A0(unsigned int id, int v);
extern "C" Cand_00285308* func_00187278(void* p, unsigned int id);
extern "C" int func_001B7B28(Cand_00285308* c, Vec_00285308* out, Vec_00285308* from);
extern "C" void func_0026FDC8(void* s);
extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_00183C98(void* p, void* pp);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" float sqrtf(float);

struct Obj_00285308 {
    char pad0[0xC];
    Body_00285308* mC;
    char pad10[0x2C4 - 0x10];
    int m2C4;
    char pad2C8[0x3C8 - 0x2C8];
    Body_00285308* m3C8;
    char pad3CC[0x594 - 0x3CC];
    Ctl_00285308* m594;
    char pad598[0x5B0 - 0x598];
    State_00285308* m5B0;
    void Target();
};

void Obj_00285308::Target()
{
    Ctl_00285308* c = m594;
    char* snd = c->m24;
    if (m5B0->mC4) return;
    Tm_00285308* tm = &c->m28;
    if (!tm->m4) return;
    unsigned int now = func_0026FDA0(tm);
    if (!(func_00203300(0x19B2C752, 0) < now)) return;
    if (m5B0->m1C) return;
    Body_00285308* best = 0;
    float bestd = func_002032A0(0x2928F080, 0);
    Vec_00285308 saved;
    Vec_00285308 v;
    for (Cand_00285308* o = func_00187278(D_0038C608, 0x3506CE64); o; o = o->m14) {
        if (!o->m1C) continue;
        Body_00285308* t = o->mC;
        if (t == mC) continue;
        v.f.x = 0.0f;
        v.f.y = 0.0f;
        v.f.z = 0.0f;
        Vec_00285308* pv = &v;
        pv->f.w = 1.0f;
        int r = func_001B7B28(o, &v, &mC->pos);
        if (r == -1) continue;
        float dx = v.f.x - mC->pos.f.x;
        float dy = v.f.y - mC->pos.f.y;
        float dz = v.f.z - mC->pos.f.z;
        float dw = v.f.w - mC->pos.f.w;
        Vec_00285308 d;
        d.f.x = dx;
        d.f.y = dy;
        d.f.z = dz;
        d.f.w = dw;
        float dist = sqrtf(dx * dx + dy * dy + dz * dz);
        if (dist < bestd) {
            bestd = dist;
            m2C4 = r;
            best = t;
            saved.q = v.q;
        }
    }
    if (!best) return;
    func_0026FDC8(snd + 0x94);
    func_0026FDC8(snd + 0x100);
    if (m3C8) {
        func_00183CB8(m3C8, &m3C8);
        m3C8 = 0;
    }
    m3C8 = best;
    func_00183C98(best, &m3C8);
    func_001848F0(mC, 0x2F184EB1, 0);
}
