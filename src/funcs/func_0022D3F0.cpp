struct Obj_0022D3F0 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8();
};

struct Flags_0022D3F0 {
    char pad[0x38];
    int m38;
};

extern Flags_0022D3F0* D_00390828;
extern int D_0038FBFC;
extern int D_0038A0E8;
extern void* D_0038C608;
extern "C" bool func_0025F0F0(Obj_0022D3F0* o);
extern "C" void* func_0025F3F0(Obj_0022D3F0* o);
extern "C" void func_0013B040(int a, void* b);
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);
extern "C" void func_0022D3C0();
extern "C" void func_00187900(void* p, void (*fn)(), int a);
extern "C" void* func_0013B0E8(int a);
extern "C" void* func_0013B000(int a);
extern "C" unsigned int func_00114E18(void* p);
extern "C" void func_0026BAB0(unsigned int mask, void* skater, unsigned int arg);
extern "C" void* func_00187B48(void* mgr, int id);
extern "C" bool func_00215778(int a, int b);
extern "C" void* func_0022E358(void* self);
extern "C" bool func_0024F860(void* p);
extern "C" void* func_00240850();
extern "C" bool func_0023F598(void* g);
extern "C" unsigned int func_0023CAE0(void* g);
extern "C" void func_001302D8(unsigned int m, unsigned int s);
extern "C" void func_001303B0();

struct Game_0022D3F0;
extern "C" void func_00230430(Game_0022D3F0* self);
extern "C" void* func_0022E040(Game_0022D3F0* self);
extern "C" void* func_0022DD38(Game_0022D3F0* self);

struct Game_0022D3F0 {
    char pad[0x70];
    int m70;
    char pad74[0x90 - 0x74];
    int m90;
    char pad94[0x39C - 0x94];
    Obj_0022D3F0* m39C;
    Obj_0022D3F0* m3A0;
    void Update();
};

void Game_0022D3F0::Update()
{
    if (!D_00390828->m38 && !D_0038FBFC) {
        if (func_0025F0F0(m39C)) {
            if (func_0025F3F0(m39C)) {
                func_0013B040(0, func_0025F3F0(m39C));
            }
            if (m70) {
                func_001F0210(0xC5C9373A, 0, 0, 0, 0);
            }
            m39C->V8();
            m70 = 1;
        } else if (m70) {
            func_001F0210(0x15674315, 0, 0, 0, 0);
            m70 = 0;
        }
        if (func_0025F0F0(m3A0)) {
            m3A0->V8();
        }
    }
    func_00230430(this);
    func_001F0210(0x1AEF674F, 0, 0, 0, 0);
    if (D_00390828->m38) {
        func_00187900(func_0022E040(this), func_0022D3C0, 0);
    }
    if (func_0022DD38(this)) {
        switch (D_0038A0E8) {
        case 1:
            if (func_0013B0E8(0)) {
                void* sk = func_0022DD38(this);
                func_0026BAB0(1, sk, func_00114E18(func_0013B0E8(0)));
            }
            break;
        case 2:
            if (func_0013B000(0)) {
                void* sk = func_00187B48(D_0038C608, 0);
                func_0026BAB0(1, sk, func_00114E18(func_0013B000(0)));
            }
            if (func_0013B000(1) && func_00187B48(D_0038C608, 1)) {
                void* sk = func_00187B48(D_0038C608, 1);
                func_0026BAB0(2, sk, func_00114E18(func_0013B000(1)));
            }
            break;
        }
    } else if (func_00215778(0, 0) && D_0038A0E8 == 1 && func_0013B0E8(0)) {
        func_0026BAB0(1, 0, func_00114E18(func_0013B0E8(0)));
    }
    if (m90) {
        m90 = 0;
    }
    if (!func_0024F860(func_0022E358(this))) {
        void* g = func_00240850();
        if (func_0023F598(g)) {
            unsigned int t = (func_0023CAE0(g) + 999) / 1000;
            func_001302D8(t / 60, t % 60);
        } else {
            func_001303B0();
        }
    }
}
