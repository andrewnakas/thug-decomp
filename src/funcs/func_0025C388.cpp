typedef int qword_0025C388 __attribute__((mode(TI)));

union Color_0025C388 {
    qword_0025C388 q;
    struct {
        float r, g, b, a;
    } c;
};

struct Ent_0025C388 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

struct Desc_0025C388 {
    int m0;
    int m4;
    int m8;
    void* mC;
    int m10;
    void* m14;
    int m18;
    int m1C;
    int m20;
    int m24;
};

struct Span_0025C388 {
    void* end;
    void* begin;
    void* m8;
    void* mC;
};

struct Obj_0025C388 {
    int m0;
    void* m4;
    int m8;
    void* mC;
    void* m10;
    char pad14[0xA5C - 0x14];
    int mA5C[64];
    int mB5C;
    void Load();
};

extern char D_00390BF8[];
extern char D_003757A0[];
extern void* D_0038DB38;
extern void* D_0038FC78;
extern char D_00452230[];
extern Color_0025C388 D_00452280[5];

extern "C" void* func_001046B0(int size);
extern "C" int func_0010F630(void* p);
extern "C" Ent_0025C388* func_0010F648(void* p, int i);
extern "C" int func_0010F638(void* p, int i);
extern "C" Ent_0025C388* func_0010F658(void* p, int a, unsigned int name, int b);
extern "C" void* func_0010F6A8(void* p, int a, unsigned int name, int b);
extern "C" void func_0010F710(void* p, int a, unsigned int name);
extern "C" void func_0025CAB0(Obj_0025C388* self, int name, int a, int b);
extern "C" void func_0025CA48(Obj_0025C388* self, int name, int a, int b);
extern "C" void* func_00144C38(void* self);
extern "C" void func_00144CE8(void* o, int a);
extern "C" void func_00144DA0(void* o);
extern "C" void func_001EE340(char* a, int b, int c);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_0022E3C8(void*, int);
extern "C" Color_0025C388 func_0025C270(void* params, unsigned int name);
extern "C" void* func_001200E0(void* o);
extern "C" int func_00123420(void* o);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" void func_00132458(Span_0025C388* s);
extern "C" int func_001D0058(void* mgr, int name, int type, Desc_0025C388* d, int size, int t1, int t2);

void Obj_0025C388::Load()
{
    char buf[0x200];
    Desc_0025C388 d;
    Span_0025C388 sp;
    int flag;
    int n = func_0010F630(m4);
    for (int i = 0; i < n; i++) {
        Ent_0025C388* e = func_0010F648(m4, i);
        int x = func_0010F638(m4, i);
        switch (e->mC) {
        case 0xEAB51346:
            func_0025CAB0(this, e->m8, x, e->m4);
            func_0010F710(m4, e->m8, e->mC);
            break;
        case 0x2E4BF21B:
            func_0025CA48(this, 0x3B423A24, x, e->m4);
            m10 = func_00144C38(func_001046B0(0xA1C));
            func_00144CE8(m10, 0x3B423A24);
            func_00144DA0(m10);
            func_0010F710(m4, e->m8, e->mC);
            break;
        case 0x5CA1497:
            func_0025CA48(this, 0x10C3DCA8, x, e->m4);
            mC = func_00144C38(func_001046B0(0xA1C));
            func_00144CE8(mC, 0x10C3DCA8);
            func_00144DA0(mC);
            func_0010F710(m4, e->m8, e->mC);
            break;
        case 0x2BBEA5C3:
            func_001EE340(D_003757A0, x, 1);
            func_0010F710(m4, e->m8, e->mC);
            break;
        case 0x524FD4E:
        case 0xE7308C1F:
        case 0xFD8697E1: {
            func_003331D0(buf, D_00390BF8, e->m8 + e->mC);
            int name = e->m8 + 0xFD8697E1;
            d.m4 = x;
            d.m0 = name;
            d.m8 = e->m4;
            d.mC = func_0010F6A8(m4, e->m8, 0x1512808D, 1);
            Ent_0025C388* f = func_0010F658(m4, e->m8, 0x1512808D, 1);
            d.m10 = f->m4;
            d.m14 = func_0010F6A8(m4, e->m8, 0xFFC529F4, 0);
            d.m20 = e->mC == 0xFD8697E1;
            d.m18 = f->m8 + f->mC;
            d.m24 = 0;
            if (e->mC == 0xE7308C1F)
                d.m1C = 0;
            else
                d.m1C = i + 200;
            void* mgr = D_0038DB38;
            bool ok = true;
            int* v = (int*)func_0010F6A8(m4, e->m8, 0x2CD4107D, 0);
            if (v) {
                void* params = (char*)func_0022E3C8(D_0038FC78, 0) + 0x4C;
                D_00452280[0] = func_0025C270(params, 0xA28FAB7F);
                D_00452280[1] = func_0025C270(params, 0xA28FAB7F);
                D_00452280[2] = func_0025C270(params, 0x0442D3C1);
                D_00452280[3] = func_0025C270(params, 0xB90F08D0);
                D_00452280[4] = func_0025C270(params, 0x1DBCFAE8);
                v++;
                int cnt = *v;
                v++;
                sp.m8 = D_00452230;
                sp.begin = v;
                sp.mC = D_00452280;
                sp.end = (char*)v + cnt * 12;
                bool a = func_0010F658(m4, e->m8 + 2, 0xFD8697E1, 0) != 0;
                bool b;
                if (a)
                    b = func_0010F658(m4, e->m8 - 1, 0xFD8697E1, 0) != 0;
                else
                    b = func_0010F658(m4, e->m8 + 1, 0xFD8697E1, 0) == 0;
                bool c = false;
                void* sk = func_0022E3C8(D_0038FC78, 0);
                void* w = func_001200E0((char*)sk + 4);
                if (w) {
                    if (func_00123420(w))
                        c = true;
                    else
                        c = false;
                }
                func_001E7DE8((char*)sk + 0x5C, 0x3F813177, &flag, 1);
                ok = false;
                if (b == c) {
                    if (a == flag)
                        ok = true;
                    else
                        ok = false;
                }
                if (ok)
                    func_00132458(&sp);
            }
            if (ok) {
                func_001D0058(mgr, name, 7, &d, 0x28, 0, 0);
                mA5C[mB5C] = name;
                mB5C++;
            }
            func_0010F710(m4, e->m8, e->mC);
            func_0010F710(m4, e->m8, 0x1512808D);
            func_0010F710(m4, e->m8, 0xFFC529F4);
            func_0010F710(m4, e->m8, 0x2CD4107D);
            break;
        }
        case 0x1512808D:
            break;
        case 0x5AC14717:
            break;
        case 0x2CD4107D:
            break;
        case 0xFFC529F4:
            break;
        }
    }
}
