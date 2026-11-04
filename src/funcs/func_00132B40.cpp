struct Node_00132B40 {
    int m0;
    unsigned int m4;
    int m8;
    Node_00132B40* mC;
    Node_00132B40* m10;
    void* m14;
};

extern "C" void func_001022D8(void* sub);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001349F0(void* mem, int a);
extern "C" Node_00132B40* func_001046B0(int size);

extern void* D_00388A70;
extern char D_0035D610[];
extern char D_0035D5E0[];

struct C_00132B40 {
    unsigned char m0;
    char pad1[0x87];
    int m88;
    int m8C;
    char m90[0x20];
    char mB0[0x20];
    void* mD0;
    int mD4;
    char padD8[0x80];
    int m158;
    int m15C;
    int m160;
    unsigned char m164;
    char pad165[0x7F];
    int m1E4;
    char pad1E8[0x80];
    int m268;
    int m26C;
    int m270;
    int m274;
    Node_00132B40* m278;
    Node_00132B40* m27C;
    void* m280;
    C_00132B40* Init(int a);
};

static inline Node_00132B40* NewNode_00132B40()
{
    Node_00132B40* n = func_001046B0(0x18);
    n->m4 = 0xFFFFFFFF;
    n->m8 = 0;
    n->m14 = D_0035D5E0;
    n->mC = n;
    n->m10 = n;
    return n;
}

C_00132B40* C_00132B40::Init(int a)
{
    m280 = D_0035D610;
    func_001022D8(m90);
    func_001022D8(mB0);
    mD4 = 0;
    mD0 = func_001349F0(func_0010A638(D_00388A70, 0x18, 1, 0), a);
    m0 = 0;
    mD4 = 0;
    m15C = 0;
    m160 = 0;
    m158 = 0;
    m164 = 0;
    m1E4 = 0;
    m26C = 0;
    m270 = 0;
    m268 = 0;
    m274 = 0;
    m278 = NewNode_00132B40();
    m27C = NewNode_00132B40();
    m88 = 0;
    m8C = 0;
    return this;
}
