struct A_002B7218 {
    int m0;
    A_002B7218();
};

struct C_002B7218 {
    int m0;
    C_002B7218(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0);
};

struct B_002B7218 {
    char pad[0x14];
    C_002B7218 m14;
    char pad2[0x30 - 0x18];
};

struct D_002B7218 {
    int m0;
    D_002B7218() {}
};

struct Obj_002B7218 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    A_002B7218 m2C;
    char pad30[0x64 - 0x30];
    A_002B7218 m64;
    char pad68[0x9C - 0x68];
    int m9C;
    int mA0;
    char padA4[0xB0 - 0xA4];
    B_002B7218 m_b[18];
    D_002B7218 m_d[16];
    char pad450[0x534 - 0x450];
    int m534;
    int m538;
    int m53C;
    int m540;
    int m544;
    Obj_002B7218();
};

Obj_002B7218::Obj_002B7218()
{
    m1C = 0x20;
    m28 = 2;
    m0 = 0;
    m4 = 0;
    m8 = 0;
    m18 = 0;
    m14 = 0;
    mC = 0;
    m10 = 0;
    m20 = 0;
    m24 = 0;
    m540 = 0;
    m53C = 0;
    m538 = 0;
    m534 = 0;
    m544 = 0;
    m9C = 0;
    mA0 = 0;
}
