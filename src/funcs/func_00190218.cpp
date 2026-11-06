typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

union Vec_00190218 {
    qword q;
    float c[4];
    Vec_00190218& operator=(const Vec_00190218& o) { q = o.q; return *this; }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void operator+=(const Vec_00190218& o) { c[0] += o.c[0]; c[1] += o.c[1]; c[2] += o.c[2]; c[3] += o.c[3]; }
    void operator-=(const Vec_00190218& o) { c[0] -= o[0]; c[1] -= o[1]; c[2] -= o[2]; c[3] -= o[3]; }
};

struct N_00190218 {
    int m0;
    int m_data;
    int m_pri;
    N_00190218* m_next;
    N_00190218* Valid() { if (m_data != -1) return this; return 0; }
};
struct Mgr_00190218 {
    int m_pad[12];
    N_00190218 m_list;
};
struct Ped_00190218 {
    char pad[0x50];
    Vec_00190218 m_pos;
    char pad2[0x50];
    Vec_00190218 m_vel;
    char pad3[0x388 - 0xC0];
    float m_radius;
};
struct Sub_00190218 { char pad[0x18]; int m_18; };

extern Mgr_00190218* D_0038FC78;
extern float D_00394328;
extern int D_0038C9B0;
extern char D_0038C9B8[];
extern "C" Ped_00190218* func_0022DE70(Mgr_00190218* mgr, int i);
extern "C" void func_00190E28(void* self);
extern "C" void* func_00184B30(void* a, void* b, int c, int d, int e);
extern "C" void func_001EFDC0(void* p);
extern "C" void* func_00131E48();
extern "C" void* func_001055B0(int a, char* b);
extern "C" void* func_00132FD0(void* a, void* b);
extern "C" void func_00135048(void* a, int b);
extern "C" int func_0010FC30();
extern "C" void func_001E72B0(void* p, unsigned int id, float v);
extern "C" void func_001A3208(void* a, void* b);
extern "C" int func_00100030(int n);

struct Obj_00190218 {
    char pad0[0xC];
    Sub_00190218* m_C;
    char pad1[0x1C - 0x10];
    float m_1C;
    char pad2[0x30 - 0x20];
    float m_30;
    float m_34;
    float m_38;
    float m_3C;
    float m_40;
    float m_44;
    char pad3[0x80 - 0x48];
    float m_80;
    void* m_84;
    char pad4[0x94 - 0x88];
    int m_94;
    void* m_98;
    char pad5[0xA0 - 0x9C];
    int m_A0;
    int m_A4;
    char pad6[0xB0 - 0xA8];
    int m_B0;
    char pad7[0xE0 - 0xB4];
    Vec_00190218 m_pos;
    Vec_00190218 m_vel;
    char pad8[0x110 - 0x100];
    Vec_00190218 m_spin;
    char pad9[0x164 - 0x120];
    float m_164;
    char pad10[0x16C - 0x168];
    void* m_16C;
    void Push();
};

void Obj_00190218::Push()
{
    Mgr_00190218* mgr = D_0038FC78;
    int count = 0;
    N_00190218* n = mgr->m_list.m_next->Valid();
    while (n) {
        count++;
        n = n->m_next->Valid();
    }
    for (int i = count - 1; i != -1; i--) {
        Ped_00190218* o = func_0022DE70(D_0038FC78, i);
        float dx = m_pos[0] - o->m_pos[0];
        float dz = m_pos[2] - o->m_pos[2];
        float r = m_30 + o->m_radius;
        if (dx * dx + dz * dz > r * r) continue;
        float dy = o->m_pos[1] - m_pos[1];
        float h = m_34 + o->m_radius;
        if (dy > h) continue;
        if (dy < -(h + D_00394328)) continue;

        Vec_00190218 d;
        d = m_pos;
        d -= o->m_pos;
        float len = sqrtf(d[0] * d[0] + d[2] * d[2]);
        d[0] = d[0] / len;
        d[2] = d[2] / len;

        Vec_00190218 v;
        v = o->m_vel;
        v -= m_vel;
        v[1] = 0.0f;
        if (fabsf(v[0]) < 0.009999999776f && fabsf(v[2]) < 0.009999999776f) return;
        float k = v[0] * d[0] + v[2] * d[2];
        if (k <= 0.0f) continue;
        if (k > 100.0f) k += 51.0f;
        else if (k > 50.0f) k += (k - 50.0f) + 50.0f;
        else k += k;

        Vec_00190218 w;
        w = v;
        float s = m_40 * k;
        w[3] = w[3] * s;
        w[1] = m_3C * s;
        len = sqrtf(w[0] * w[0] + w[2] * w[2]);
        float wx = w[0] / len + d[0];
        float wz = w[2] / len + d[2];
        len = sqrtf(wx * wx + wz * wz);
        w[0] = wx / len * m_38 * s;
        w[2] = wz / len * m_38 * s;

        float rad = m_34;
        Vec_00190218 p;
        p = o->m_pos;
        p[0] -= m_pos[0];
        p[2] -= m_pos[2];
        p[1] = 0.0f;
        float pl = sqrtf(p[0] * p[0] + p[2] * p[2]);
        if (pl > 0.0f) {
            float ps = rad / pl;
            p[0] = p[0] * ps;
            p[2] = p[2] * ps;
        }
        if (dy > 0.0f) p[1] = o->m_pos[1] - m_pos[1];
        else if (dy < -D_00394328) p[1] = o->m_pos[1] + D_00394328 - m_pos[1];
        else p[1] = -12.0f;

        m_vel += w;

        Vec_00190218 e;
        Vec_00190218 c;
        float cx = p[1] * w[2] - p[2] * w[1];
        float cy = p[2] * w[0] - p[0] * w[2];
        float cz = p[0] * w[1] - p[1] * w[0];
        c[0] = cx; c[1] = cy; c[2] = cz; c[3] = 0.0f;
        float t0 = m_1C * 0.6000000238f;
        float t = m_44 * t0;
        float ex = c[0] * t;
        float ey = c[1] * t;
        float ez = c[2] * t;
        float ew = c[3] * t;
        e[0] = ex; e[1] = ey; e[2] = ez; e[3] = ew;
        m_spin += e;

        func_00190E28(this);
        m_164 = m_80;
        if (m_84) func_001EFDC0(func_00184B30(m_C, m_84, m_94, 0, 0));
        void* a = func_00131E48();
        void* r2 = func_00132FD0(a, func_001055B0(m_C->m_18, D_0038C9B8));
        if (r2) func_00135048(r2, 0);
        int now = func_0010FC30();
        if (now - m_B0 <= 0) return;
        if (now - D_0038C9B0 <= 0) return;
        if (!m_98) return;
        func_001E72B0(m_98, 0x9E497FC6, sqrtf(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]) * 0.1000000015f);
        func_001A3208(m_16C, m_98);
        m_B0 = func_0010FC30() + (unsigned)((func_00100030(100) + 50) * m_A0) / 100;
        D_0038C9B0 = func_0010FC30() + (unsigned)((func_00100030(100) + 50) * m_A4) / 100;
        return;
    }
}
