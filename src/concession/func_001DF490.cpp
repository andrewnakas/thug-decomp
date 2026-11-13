/* force: {"kind": "ga", "before": [118, 117]} */
/* sym: __12Snd_001DF490 = 0x001DC540 */
/* sym: _$_12Snd_001DF490 = 0x001DC578 */
struct Vec_001DF490 {
    float x, y, z, w;
};

class Snd_001DF490 {
public:
    float m0;
    float m4;
    char pad8[0x18];
    Snd_001DF490();
    ~Snd_001DF490();
};

struct Voice_001DF490 {
    int m0;
    int m4;
    float m8;
    float mC;
    char pad10[0xC];
    int m1C;
    int m20;
    char pad24[4];
};

struct Body_001DF490 {
    char pad0[0x50];
    char m50[0x10];
};

struct Obj_001DF490 {
    char pad0[0xC];
    Body_001DF490* mC;
    char pad10[0xC];
    int m1C[4];
};

extern void* D_0038E0A0;
extern int D_0038E128;
extern Obj_001DF490* D_003F2220[4];
extern Voice_001DF490 D_003EE8E0[3];

extern "C" int func_001DCAF8(void* m);
extern "C" int func_001DED40();
extern "C" void func_001DC6D0(Snd_001DF490* s);
extern "C" void* func_0013B108(void* p, int a);
extern "C" int func_001A3D00(Obj_001DF490* o, void* c, Vec_001DF490* out);
extern "C" void func_001A3C90(Vec_001DF490* out, Obj_001DF490* o, void* c);
extern "C" void func_001DDB00(void* m, Snd_001DF490* s, Vec_001DF490* pos, float f, int a, void* c, Vec_001DF490* vel);
extern "C" float func_001DC5F0(Snd_001DF490* s);
extern "C" void func_001E53A0(unsigned int name, int a);
extern "C" int func_001DF740(void* a, Snd_001DF490* s, float f, int b, int c, int d);

extern "C" int func_001DF490(Obj_001DF490* self, void* a1, int a2, int flag, int t0, int t1, float f12, float f13, float f14)
{
    void* m = D_0038E0A0;
    if (func_001DCAF8(m)) return 0;
    if (func_001DED40()) return 0;
    Snd_001DF490 snd;
    func_001DC6D0(&snd);
    if (flag) {
        void* c = func_0013B108(self->mC->m50, 0);
        if (c) {
            Vec_001DF490 vel;
            Vec_001DF490 pos;
            Vec_001DF490* pv = &vel;
            if (!func_001A3D00(self, c, pv)) pv = 0;
            func_001A3C90(&pos, self, c);
            func_001DDB00(m, &snd, &pos, f12, t0, c, pv);
        } else {
            func_001DC6D0(&snd);
        }
        if (__builtin_fabsf(func_001DC5F0(&snd)) < 2.0f) func_001E53A0(0xD7BB618D, 0);
    } else {
        snd.m0 = f13;
        snd.m4 = f13;
    }
    int id = func_001DF740(a1, &snd, f14, a2, t1, 0);
    if (id) {
        if (D_003F2220[D_0038E128]) {
            D_003F2220[D_0038E128]->m1C[D_0038E128] = 0;
            D_003F2220[D_0038E128] = 0;
        }
        D_003F2220[D_0038E128] = self;
        self->m1C[D_0038E128] = id;
        int i;
        if (f13 != 100.0f) {
            for (i = 0; i < 3; i++) {
                if (D_003EE8E0[i].m4 == id) {
                    D_003EE8E0[i].m8 = D_003EE8E0[i].m8 * f13 * 0.01f;
                    D_003EE8E0[i].mC = f12;
                }
            }
        }
        if (!flag) {
            for (i = 0; i < 3; i++) {
                if (D_003EE8E0[i].m4 == id) D_003EE8E0[i].m1C = 0;
            }
        } else {
            for (i = 0; i < 3; i++) {
                if (D_003EE8E0[i].m4 == id) {
                    D_003EE8E0[i].m1C = 1;
                    D_003EE8E0[i].m20 = t0;
                }
            }
        }
    }
    return id;
}
