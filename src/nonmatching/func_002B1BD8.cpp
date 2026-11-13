/* fuzzy: 97.2 */
extern char D_00379850[];
extern char D_00379640[];

extern "C" int func_003331D0(char* buf, char* fmt, ...);

struct Node_002B1BD8 {
    int m0;
    Node_002B1BD8* m4;
    int m8;
    Node_002B1BD8* mC;
    Node_002B1BD8* m10;
    void* m14;
    Node_002B1BD8()
    {
        m14 = D_00379850;
        m4 = this;
        m8 = 0;
        mC = this;
        m10 = this;
    }
};

struct Z_002B1BD8 {
    unsigned int v;
    Z_002B1BD8() { v = 0; }
};

struct Elem_002B1BD8;

struct Sub_002B1BD8 {
    char str[0x38];
    short m84[8][3];
    short mB4[8][3];
    Z_002B1BD8 mE4[8];
    Z_002B1BD8 m104[8];
    signed char m124[8];
    signed char m12C[8];
    Sub_002B1BD8(Elem_002B1BD8* owner);
};

struct Elem_002B1BD8 : Node_002B1BD8 {
    int m18;
    char pad1C[0x28 - 0x1C];
    int m28;
    int m2C;
    int m30;
    char m34[0x10];
    int m44;
    int m48;
    Sub_002B1BD8 m4C;
    char pad134[0x14C - 0x134];
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    void SetId(const int& v) { m14C = v; }
    Elem_002B1BD8(unsigned int id);
};

inline Sub_002B1BD8::Sub_002B1BD8(Elem_002B1BD8* owner)
{
    owner->m14C = 0;
    func_003331D0(owner->m34, D_00379640, str);
}

Elem_002B1BD8::Elem_002B1BD8(unsigned int id) : m4C(this)
{
    for (int i = 0; i < 8; i++) {
        ((unsigned int*)m4C.mE4)[i] = 0xFFFFFFFF;
        m4C.m12C[i] = -1;
        m4C.m124[i] = -1;
        for (int j = 0; j < 3; j++) {
            m4C.m84[i][j] = -1;
            m4C.mB4[i][j] = -1;
        }
    }
    SetId(id);
    m160 = 7;
    m168 = 0;
    m154 = 0;
    m164 = 0;
    m18 = 0;
    m48 = 0;
    m158 = 0;
    m15C = 0;
    m30 = 0;
    m28 = 0;
    m2C = 0;
    m44 = 0;
}
