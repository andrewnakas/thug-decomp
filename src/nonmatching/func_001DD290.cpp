/* fuzzy: 81.3 */
struct Params_001DD290 {
    float x, y, z;
    int mC;
};

struct Sound_001DD290 {
    char pad0[4];
    int m4;
    char pad8[8];
    float m10;
    char m14[1];
};

struct Info_001DD290 {
    int m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    int m28;
};

struct Entry_001DD290 {
    int m0;
    int m4;
    Sound_001DD290* m8;
    Info_001DD290 mC;
    char pad38[4];
};

extern int D_0038881C;
extern Entry_001DD290 D_003EC2F8[];
extern "C" bool func_001DC418();
extern "C" Sound_001DD290* func_001DCA18(int a, int b);
extern "C" bool func_001E53A0(unsigned int a, int b);
extern "C" void func_001DC820(int a, int b, float* vol);
extern "C" void func_001DD1E8(int a, int b, float* vol, Sound_001DD290* s);
extern "C" int func_001E1CA0(void* p, int b, int c, float vol);
extern "C" int func_001DC908(int a, int b);

int func_001DD290(int a, int id, int c, int d, Params_001DD290* p, float vol)
{
    if (func_001DC418()) return 0;
    Sound_001DD290* s = func_001DCA18(a, id);
    if (!s) return 0;
    if (!d) d = id;
    if (!D_0038881C && func_001E53A0(0xD7BB618D, 0) && !p) {
        func_001DC820(a, d, &vol);
    }
    func_001DD1E8(a, c, &vol, s);
    int idx = func_001E1CA0(s->m14, c, (s->m4 >> 4) & 1, vol);
    if (idx == -1) return 0;
    Entry_001DD290* e = &D_003EC2F8[idx];
    e->m4 = d;
    e->m0 = func_001DC908(a, d);
    e->m8 = s;
    Info_001DD290* info = &e->mC;
    if (p) {
        float x = p->x;
        info->m8 = x;
        float y = p->y;
        info->mC = y;
        float z = p->z;
        if (z == 0.0f) z = s->m10;
        info->m4 = z;
        info->m18 = x;
        info->m1C = y;
        info->m20 = 0.0f;
        info->m10 = x;
        info->m14 = y;
        info->m24 = 0.0f;
        info->m28 = p->mC;
    } else {
        info->m4 = 0.0f;
        info->m8 = 100.0f;
        info->mC = 100.0f;
        info->m28 = 0;
    }
    info->m0 = id;
    if (!D_0038881C) func_001E53A0(0xD7BB618D, 0);
    return e->m0;
}
