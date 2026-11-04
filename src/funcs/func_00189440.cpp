extern void* D_00388A70;
extern int D_00361D90[];
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0018AB90(void* p, int bits);
extern "C" void* func_0018AC70(void* p, int bits);
extern "C" void func_00188D70(void* p);

struct E_00189440 {
    int a;
    int b;
    int c;
};

struct C_00189440 {
    int m0;
    int m4;
    void* m8;
    void* mC;
    void* m10;
    int m14;
    int m18;
    int m1C;
    char m20[0xB034 - 0x20];
    int mB034;
    E_00189440 m_arr[40];
    int mB218;
    int* m_vtbl;
    C_00189440* Init();
};

C_00189440* C_00189440::Init()
{
    m_vtbl = D_00361D90;
    func_00188D70(m20);
    m8 = func_0018AB90(func_0010A638(D_00388A70, 0x18, 1, 0), 8);
    mC = func_0018AB90(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    m10 = func_0018AC70(func_0010A638(D_00388A70, 0x18, 1, 0), 8);
    m4 = 0;
    m14 = 0;
    m18 = 0;
    m1C = 0;
    mB034 = 0;
    for (int i = 39; i >= 0; i--) m_arr[i].b = 0;
    mB218 = 0;
    return this;
}
