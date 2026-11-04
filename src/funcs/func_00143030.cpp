extern int D_00388A70;
extern float D_0038A64C;
extern float D_0038A650;
extern float D_0038A654;
extern "C" void* func_0010A638(int heap, unsigned int size, int, int);

struct A_00143030 {
    float v[4];
    A_00143030() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct B_00143030 {
    float v[4];
    B_00143030() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct M_00143030 {
    float v[16];
    M_00143030() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class C_00143030 {
public:
    A_00143030* m0;
    B_00143030* m4;
    int m8;
    M_00143030* mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    int m20;
    C_00143030(int n);
    virtual ~C_00143030();
    virtual void F();
};

C_00143030::C_00143030(int n)
{
    m0 = new A_00143030[n];
    m4 = new B_00143030[n];
    mC = new M_00143030[n];
    m20 = n;
    m14 = 128.0f;
    m10 = D_0038A64C;
    m18 = D_0038A650;
    m1C = D_0038A654;
}
