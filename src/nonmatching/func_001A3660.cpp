/* cflags: -O1 */
/* fuzzy: 73.8 */
struct Ent_001A3660 {
    int m0;
    float m4;
    int m8, mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    int m24;
    int m28;
    unsigned int m2C;
};
struct Out_001A3660 {
    int m0, m4, m8;
    int mC;
    int m10, m14;
    float m18;
    float m1C;
    float m20;
    float m24;
};
extern void* D_0038E0A0;
extern "C" unsigned int func_0010FC30();
extern "C" void func_001A37A8(void* p, Ent_001A3660* e);
extern "C" int func_0013B108(void* p, float* out);
extern "C" int func_001A3A28(void* p, int a, int b, int c, float x, float y);
extern "C" Out_001A3660* func_001DEA98(void* p, void* o, int a);
struct Obj_001A3660 {
    char pad[0x3C];
    Ent_001A3660 m3C[2];
    char pad2[0xA0 - 0x9C];
    int mA0;
    void Update();
};

void Obj_001A3660::Update()
{
    int i = 0;
    unsigned int now = func_0010FC30();
next:
    if (m3C[i].m0) {
        Ent_001A3660* e = &m3C[i];
        func_001A37A8(this, e);
        if (now >= e->m2C) {
        float t;
        if (func_0013B108(&mA0, &t) && t < e->m4 + 240.0f) {
            if (func_001A3A28(this, e->m0, e->m28, 0, e->m14, e->m10)) {
                Out_001A3660* o = func_001DEA98(D_0038E0A0, this, e->m0);
                float f = e->m1C;
                o->m1C = f;
                o->m18 = e->m18;
                o->m20 = e->m20;
                o->m24 = f * 0.01f;
                o->mC = 0;
                e->m0 = 0;
            }
        } else {
            e->m2C = now + (int)((t - e->m4) * 1.66666675f) + 0x14D;
        }
        }
    }
    i++;
    if (i < 2) goto next;
}
