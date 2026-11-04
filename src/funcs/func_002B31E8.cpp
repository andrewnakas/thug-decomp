struct Thread_002B31E8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void (*m18)();
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

struct Pool_002B31E8 {
    char pad[0x108];
    int m108;
};

struct Net_002B31E8 {
    char pad0[4];
    void* m4;
    char pad8[0x19C - 0x8];
    unsigned int m19C;
    char pad1A0[0x99D4 - 0x1A0];
    char m99D4[0x9DD4 - 0x99D4];
    int m9DD4;
    unsigned int m9DD8;
    bool TimedOut(unsigned int now, unsigned int ms);
};

extern Pool_002B31E8* D_00388A70;
extern int D_00392428;
extern char D_00379880[];
extern char D_00379898[];
extern char D_003798B0[];
extern char D_003798C8[];
extern char D_003798E0[];
extern char D_003798F8[];
extern char D_00379918[];
extern char D_00379938[];
extern char D_00392438[];
extern char D_00392440[];
extern "C" int func_002B5688(Net_002B31E8* n);
extern "C" int func_002B5690(Net_002B31E8* n);
extern "C" void func_002B5608(Net_002B31E8* n, int mode);
extern "C" void func_002B4248(Net_002B31E8* n);
extern "C" unsigned int func_0010FC30();
extern "C" void func_0010A950(Pool_002B31E8* p, int v);
extern "C" void func_0010A9B0(Pool_002B31E8* p);
extern "C" void func_001E0038(int v);
extern "C" void func_001F0938(char* s, void* p, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" char* func_001E5518(char* name, int v);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_002E4A08(int v);
extern "C" void func_002E49E8();
extern "C" void func_002E4550();
extern "C" void func_00106038(Thread_002B31E8* t);
extern "C" int func_002A84B8(void* m);
extern "C" void func_002A84C0(void* m, int v);
extern "C" void* func_002A84D0(void* m);
extern "C" int func_0031BAC0(void* p, void* o);
extern "C" void func_002D2DB8(void* p);
extern "C" void func_002D2D40(void* p);
extern "C" int func_002D2FB8(void* p, int v);
extern "C" void func_002D2EB8(void* p);
extern "C" void func_002B40A8();
extern "C" void func_002B4168();

inline bool Net_002B31E8::TimedOut(unsigned int now, unsigned int ms) { return now - m9DD8 > ms; }

struct Obj_002B31E8 {
    char pad[0x20];
    Net_002B31E8* m20;
    void Update();
};

void Obj_002B31E8::Update()
{
    Thread_002B31E8 t;
    char buf[0x100];
    Net_002B31E8* n = m20;
    switch (func_002B5688(n)) {
    case 0:
        if (n->m19C != 0 && n->m19C < func_0010FC30()) {
            func_002B5608(n, func_002B5690(n));
        }
        break;
    case 1:
    case 2:
        break;
    case 3:
    case 7:
        func_001E0038(1);
        if (D_00392428 == 0) {
            func_001F0938(D_00379880, 0, 0, 0, -1, 0, 0, 0, 0, 0);
        } else {
            void* s = func_001E6978(func_001190D0(8));
            func_003331D0(buf, D_00392438, D_00392428, func_001E5518(D_00379898, 0));
            func_001E7A30(s, func_001F0D78(D_00392440), 3, buf);
            func_001F0938(D_003798B0, s, 0, 0, -1, 0, 0, 0, 0, 0);
            if (s) func_001E6AE8(s, 3);
        }
        func_002B5608(n, 0);
        n->m19C = 0;
        t.m18 = func_002B40A8;
        t.m24 = 10;
        t.m1C = func_002A84B8(n);
        t.m20 = 0x8000;
        t.m10 = 0x151;
        func_00106038(&t);
        func_002A84C0(n, t.m14);
        func_0031BAC0(func_002A84D0(n), n);
        break;
    case 4:
        func_0010A950(D_00388A70, D_00388A70->m108);
        if (n->TimedOut(func_0010FC30(), 15000)) {
            func_002E4A08(n->m9DD4);
            func_002B5608(n, 8);
        } else {
            func_002E49E8();
        }
        func_0010A9B0(D_00388A70);
        break;
    case 5:
        func_002E4550();
        func_001E0038(1);
        t.m24 = 10;
        t.m18 = func_002B4168;
        t.m1C = func_002A84B8(n);
        t.m20 = 0x8000;
        t.m10 = 0x151;
        func_00106038(&t);
        func_002A84C0(n, t.m14);
        func_0031BAC0(func_002A84D0(n), n);
        break;
    case 9:
        func_0010A950(D_00388A70, D_00388A70->m108);
        if (n->TimedOut(func_0010FC30(), 15000)) {
            func_002E4A08(n->m9DD4);
            func_002B5608(n, 6);
        } else {
            func_002E49E8();
        }
        func_0010A9B0(D_00388A70);
        break;
    case 6: {
        func_002E4550();
        func_002B4248(n);
        void* s = func_001E6978(func_001190D0(8));
        func_001E7A30(s, func_001F0D78(D_00392440), 3, n->m99D4);
        func_001F0370(D_003798C8, s, 0, 0);
        if (s) func_001E6AE8(s, 3);
        func_002B5608(n, 0);
        n->m19C = 0;
        break;
    }
    case 8:
        func_002E4550();
        func_001F0370(D_003798E0, 0, 0, 0);
        func_002B5608(n, 2);
        n->m19C = 0;
        break;
    case 10:
        func_001F0370(D_003798F8, 0, 0, 0);
        func_002D2DB8(n->m4);
        func_002D2D40(n->m4);
        break;
    case 11:
        func_002B5608(n, 0);
        n->m19C = 0;
        break;
    case 13: {
        func_002D2DB8(n->m4);
        void* s = func_001E6978(func_001190D0(8));
        func_001E7A30(s, func_001F0D78(D_00392440), 3, func_001E5518(D_00379918, 0));
        func_001F0370(D_00379938, s, 0, 0);
        if (s) func_001E6AE8(s, 3);
        func_002B5608(n, 2);
        break;
    }
    case 12:
        if (func_002D2FB8(n->m4, 0) == 0) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7A30(s, func_001F0D78(D_00392440), 3, func_001E5518(D_00379918, 0));
            func_001F0370(D_00379938, s, 0, 0);
            if (s) func_001E6AE8(s, 3);
            func_002B5608(n, 2);
        } else {
            func_002B5608(n, 0xE);
        }
        func_001E0038(0);
        break;
    case 14:
        func_002D2EB8(n->m4);
        func_002B5608(n, 2);
        break;
    }
}
