class A_0025C988 {
public:
    char pad0[0xA1C];
    virtual ~A_0025C988();
};

struct Pool_0025C988 {
    char pad0[0x114];
    int m114;
};

extern Pool_0025C988* D_00388A70;
extern "C" void func_0010A950(Pool_0025C988* p, int v);
extern "C" void func_0010A9B0(Pool_0025C988* p);
extern "C" void func_001E0A88();
extern "C" bool func_001DF9F8();
extern "C" void func_001DFA30(float f);
extern "C" void func_0010FB08();

struct Mgr_0025C988 {
    int m0;
    A_0025C988* m4;
    char pad8[0xB60 - 8];
    int mB60;
    int Shutdown();
};

extern "C" void func_0025C388(Mgr_0025C988* m);
extern "C" void func_0025C930(Mgr_0025C988* m);

int Mgr_0025C988::Shutdown()
{
    func_0010A950(D_00388A70, D_00388A70->m114);
    func_0025C388(this);
    func_0025C930(this);
    func_0010A9B0(D_00388A70);
    delete m4;
    m4 = 0;
    while (!mB60) {
        func_001E0A88();
        if (func_001DF9F8()) {
            func_001DFA30(-1.0f);
            mB60 = 1;
            break;
        }
        func_0010FB08();
    }
    return 1;
}
