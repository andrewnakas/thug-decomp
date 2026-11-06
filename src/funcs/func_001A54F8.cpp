typedef int qword_001A54F8 __attribute__((mode(TI)));

struct Vec_001A54F8 {
    qword_001A54F8 q;
};

struct Mat_001A54F8 {
    Vec_001A54F8 r[4];
};

struct Model_001A54F8 {
    char pad[0x18];
    unsigned int m18;
    char pad1C[0x50 - 0x1C];
    Vec_001A54F8 m50;
    char pad60[0x10];
    Mat_001A54F8 m70;
    char padB0[0x10];
    Mat_001A54F8 mC0;
};

struct Obj_001A54F8;
extern "C" float func_0010FAB8();
extern "C" void func_001A5760(Obj_001A54F8* o);
extern "C" void func_001A5788(Obj_001A54F8* o);
extern "C" void func_001A88B8(Obj_001A54F8* o);
extern "C" void func_001A8360(Obj_001A54F8* o);
extern "C" int func_001A80B8(Obj_001A54F8* o);
extern "C" void func_001A83D8(Obj_001A54F8* o);
extern "C" void func_001A96B8(Obj_001A54F8* o);
extern "C" void func_001A9858(Obj_001A54F8* o);

struct Obj_001A54F8 {
    char pad[0xC];
    Model_001A54F8* mC;
    char pad10[0xC];
    int m1C;
    char pad20[0x210 - 0x20];
    float m210;
    char pad214[0x250 - 0x214];
    Vec_001A54F8 m250;
    void Update();
};

void Obj_001A54F8::Update()
{
    m210 = func_0010FAB8();
    if (m1C & 0x80) {
        func_001A5760(this);
        func_001A5788(this);
    }
    if (m1C & 7)
        func_001A88B8(this);
    if (m1C & 0x20)
        func_001A8360(this);
    if (m1C & 8) {
        if (func_001A80B8(this))
            m1C &= ~8;
    } else if (m1C & 0x10) {
        func_001A83D8(this);
    } else if (m1C & 0x200) {
        func_001A96B8(this);
    }
    if (m1C & 0x100) {
        func_001A9858(this);
        mC->m50 = m250;
    }
    Model_001A54F8* m = mC;
    if (m->m18 >= 0x10) {
        Mat_001A54F8* d = &m->mC0;
        *d = m->m70;
    }
}
