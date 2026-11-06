typedef int qword_001AA1D0 __attribute__((mode(TI)));

struct Vec_001AA1D0 {
    union {
        struct { float x, y, z, w; };
        qword_001AA1D0 q;
    };
    Vec_001AA1D0() {}
    Vec_001AA1D0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Model_001AA1D0 {
    char pad[0x50];
    Vec_001AA1D0 m50;
    char pad60[0x104 - 0x60];
    unsigned int m104;
};

struct Skin_001AA1D0 {
    char pad[0x260];
    void* m260;
};

struct Player_001AA1D0 {
    int m0;
    char pad4[0xC];
    Vec_001AA1D0 m10;
};

struct Comp_001AA1D0 {
    char pad[0xC];
    Model_001AA1D0* mC;
    char pad10[4];
    Comp_001AA1D0* m14;
    char pad18[4];
    int m1C;
    char pad20[4];
    float m24;
    float m28;
    int m2C;
    Skin_001AA1D0* m30;
    int m34;
    char pad38[0x4C - 0x38];
    int m4C;
};

extern char* D_0038FC78;
extern void* D_0038C608;
extern "C" Comp_001AA1D0* func_00187278(void* mgr, unsigned int type);
extern "C" void func_001851B0(Model_001AA1D0* m, int on);
extern "C" void func_0013D950(void* skin, int on);
extern "C" void func_001A9F08(Comp_001AA1D0* c);

extern "C" void func_001AA1D0()
{
    Player_001AA1D0* pl = (Player_001AA1D0*)(D_0038FC78 + 0x470);
    Comp_001AA1D0* c = func_00187278(D_0038C608, 0xCE0CA665);
    while (c) {
        c->m28 = 0.0f;
        c->m34 = 0;
        if (c->m2C) {
            c->m2C--;
            continue;
        }
        if (!pl->m0 && !c->m1C) {
            if (c->m4C) {
                c->m4C--;
            } else {
                Model_001AA1D0* m = c->mC;
                Vec_001AA1D0 d(m->m50.x - pl->m10.x, m->m50.y - pl->m10.y, m->m50.z - pl->m10.z, m->m50.w - pl->m10.w);
                float dist = d.x * d.x + d.y * d.y + d.z * d.z;
                c->m28 = dist;
                if (c->m24 < dist)
                    c->m34 = 1;
                else
                    c->m34 = 0;
            }
        }
        if (c->m34) {
            if (!(c->mC->m104 & 2))
                func_001851B0(c->mC, 1);
        } else {
            if (c->mC->m104 & 2)
                func_001851B0(c->mC, 0);
        }
        if (c->m30) {
            if (c->m4C) {
                if (c->m30->m260)
                    func_0013D950(c->m30->m260, 1);
            } else {
                func_001A9F08(c);
            }
        }
        c = c->m14;
    }
}
