/* sym: _vt$12Mgr_0025BFC8 = 0x00375850 */
typedef int qword __attribute__((mode(TI)));

class A_0025BFC8 {
public:
    char pad0[0xA1C];
    virtual ~A_0025BFC8();
};

class B_0025BFC8 {
public:
    char pad0[0xA18];
    virtual ~B_0025BFC8();
};

class C_0025BFC8 {
public:
    char pad0[0x8];
    virtual ~C_0025BFC8();
};

struct Item_0025BFC8 {
    char pad0[0x50];
    qword m50;
};

struct Ent2_0025BFC8 {
    char pad0[0xC];
    int mC;
    int m10;
    C_0025BFC8* m14;
    char pad18[8];
};

struct Ent1_0025BFC8 {
    int m0;
    B_0025BFC8* m4;
};

struct Pool_0025BFC8;
extern Pool_0025BFC8* D_00388A70;
extern void* D_0038DB38;
extern "C" void func_0010A8D8(Pool_0025BFC8* p, void* m);
extern "C" void* func_00185578(void* o, unsigned int name);
extern "C" void* func_0018DF68(void* o);
extern "C" Item_0025BFC8* func_00184D70(void* o);
extern "C" void func_0013F010(void* m, void* v);
extern "C" void func_0013D910(void* m, int v);
extern "C" void func_0013EE48(void* m, int v);
extern "C" void* func_001D05B0(void* m, int id, int a);
extern "C" void func_001D04E0(void* m, void* o);
extern "C" void func_001DEEE0();
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);
extern "C" void func_001EE370(unsigned int name);

struct Comp_0025BFC8 {
    char pad0[0x260];
    void* m260;
};

class Mgr_0025BFC8 {
public:
    int m0;
    A_0025BFC8* m4;
    int m8;
    B_0025BFC8* mC;
    B_0025BFC8* m10;
    char pad14[0xC];
    char m20[0x10];
    int m30;
    int m34;
    char pad38[8];
    qword m40;
    int pad50;
    Ent2_0025BFC8 m54[64];
    int m854;
    Ent1_0025BFC8 m858[64];
    int mA58;
    int mA5C[64];
    int mB5C;
    char padB60[0x20];
    virtual void Update();
    virtual ~Mgr_0025BFC8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_0025BFC8::~Mgr_0025BFC8()
{
    if (m4) {
        delete m4;
        m4 = 0;
    }
    if (mC) {
        delete mC;
        mC = 0;
    }
    if (m10) {
        delete m10;
        m10 = 0;
    }
    for (int i = 0; i < mA58; i++) {
        Ent1_0025BFC8* e = &m858[i];
        delete e->m4;
        e->m4 = 0;
    }
    for (int j = 0; j < m854; j++) {
        Ent2_0025BFC8* e = &m54[j];
        void* c = func_00185578(e->m14, 0x286A8D26);
        if (e->mC) {
            Item_0025BFC8* it = func_00184D70(func_0018DF68(c));
            void* m = ((Comp_0025BFC8*)func_00185578(it, 0x286A8D26))->m260;
            func_0013F010(m, m20);
            func_0013D910(m, m30);
            func_0013EE48(m, m34);
            it->m50 = m40;
        }
        delete e->m14;
        e->m14 = 0;
    }
    for (int k = 0; k < mB5C; k++) {
        void* mgr = D_0038DB38;
        func_001D04E0(mgr, func_001D05B0(mgr, mA5C[k], 1));
        mA5C[k] = 0;
    }
    func_001DEEE0();
    func_001F0210(0x7216D8DA, 0, 0, 0, 0);
    func_001EE370(0xA1408E6E);
}
