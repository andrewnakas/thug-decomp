extern char D_00371C78[];
extern char D_003714C0[];
extern char D_00392B90[];
extern int D_0039418C;

struct IterA_002D1B90 {
    int m0;
    int m4;
    void* m8;
    IterA_002D1B90() { m8 = D_00371C78; m4 = 0; }
    ~IterA_002D1B90() { m8 = D_00371C78; }
};

struct IterB_002D1B90 {
    int m0;
    int m4;
    void* m8;
    IterB_002D1B90() { m8 = D_003714C0; m4 = 0; }
    ~IterB_002D1B90() { m8 = D_003714C0; }
};

struct Elem_002D1B90 {
    char pad[0x2C];
    int m2C;
    char m30[4];
    char m34[4];
};

struct Obs_002D1B90 {
    char m0;
    char m1[0x1F];
    unsigned int m20;
    char pad2[0xC];
    int m30;
};

struct Mgr_002D1B90;
extern Mgr_002D1B90* D_00392068;

extern "C" Elem_002D1B90* func_002A53F8(Mgr_002D1B90* self, IterA_002D1B90* it, int a);
extern "C" Elem_002D1B90* func_002A5490(Mgr_002D1B90* self, IterA_002D1B90* it, int a);
extern "C" Obs_002D1B90* func_002A5520(Mgr_002D1B90* self, IterB_002D1B90* it);
extern "C" Obs_002D1B90* func_002A5558(Mgr_002D1B90* self, IterB_002D1B90* it);
extern "C" int func_002B1FE8(Elem_002D1B90* e);
extern "C" int func_002B30F0(Elem_002D1B90* e);
extern "C" void func_002E2E48(void* out, int v);
extern "C" void func_002E2E88(void* out, char* s);

extern "C" void func_002D1B90(void* self, int type, int idx, void* out)
{
    D_0039418C = 1;
    switch (type) {
    case 0x39: {
        Mgr_002D1B90* m = D_00392068;
        IterA_002D1B90 a;
        IterB_002D1B90 b;
        int n = 0;
        for (Elem_002D1B90* e = func_002A53F8(m, &a, 1); e; e = func_002A5490(m, &a, 1)) {
            if (!func_002B1FE8(e) || func_002B30F0(e)) {
                if (n == idx) {
                    func_002E2E48(out, e->m2C);
                    return;
                }
                n++;
            }
        }
        for (Obs_002D1B90* o = func_002A5520(m, &b); o; o = func_002A5558(m, &b)) {
            if ((o->m20 & 0x1C) != 4) {
                if (n == idx) {
                    func_002E2E48(out, o->m30);
                    return;
                }
                n++;
            }
        }
        func_002E2E88(out, D_00392B90);
        break;
    }
    case 0x15: {
        Mgr_002D1B90* m = D_00392068;
        IterA_002D1B90 a;
        IterB_002D1B90 b;
        int n = 0;
        for (Elem_002D1B90* e = func_002A53F8(m, &a, 1); e; e = func_002A5490(m, &a, 1)) {
            if (!func_002B1FE8(e) || func_002B30F0(e)) {
                if (n == idx) {
                    func_002E2E88(out, e->m34);
                    return;
                }
                n++;
            }
        }
        for (Obs_002D1B90* o = func_002A5520(m, &b); o; o = func_002A5558(m, &b)) {
            if ((o->m20 & 0x1C) != 4) {
                if (n == idx) {
                    func_002E2E88(out, o->m1);
                    return;
                }
                n++;
            }
        }
        func_002E2E88(out, D_00392B90);
        break;
    }
    case 0x18:
        func_002E2E88(out, D_00392B90);
        break;
    }
}
