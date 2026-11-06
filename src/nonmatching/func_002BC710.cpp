/* fuzzy: 72.2 */
/* nonmatch func_002BC710: best earlier draft (thug-claude-lane3/work/w53/p1/func_002BC710.fail), 45 of 151 words differ. */
struct Box_002BC710 {
    unsigned char m[6];
    Box_002BC710(unsigned char x = 0, signed char y = 0, unsigned char z = 0,
                 unsigned char w = 0, unsigned char h = 0, unsigned char d = 0);
};

struct Keys_002BC710 {
    int a;
    int b;
    int c;
};

extern "C" Box_002BC710* func_002BAA28(Box_002BC710* b, unsigned char x, signed char y, unsigned char z,
                                        unsigned char w, unsigned char h, unsigned char d);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_002B7218(void* p);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);
extern void* D_00388A70;
extern char D_0037A480[];
extern char D_0037A498[];
extern char D_0037A4A8[];

struct Obj_002BC710;
extern Obj_002BC710* D_00392754;
extern "C" void func_002C3778(Obj_002BC710* o);

struct Obj_002BC710 {
    void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    Keys_002BC710 m18[8];
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98[58][58];
    int m3528;
    Box_002BC710 m352C;
    Box_002BC710 m3532;
    int m3538;
    char pad353C[0x6A60 - 0x353C];
    void* m6A60;
    int m6A64;
    unsigned char m6A68;
    char pad6A69[0x6AA8 - 0x6A69];
    Box_002BC710 m6AA8[8];
    int pad6AD8[10];
    int m6B00;
    Obj_002BC710();
};

Obj_002BC710::Obj_002BC710()
{
    char buf1[128];
    char buf2[128];
    char buf3[128];
    m0 = func_002B7218(func_0010A638(D_00388A70, 0x560, 1, 0));
    m80 = 0;
    m84 = 0;
    m88 = 0;
    m8C = 0;
    m94 = 0;
    m90 = 0;
    m3538 = 0;
    for (int i = 0; i < 58; i++) {
        for (int j = 0; j < 58; j++) {
            m98[i][j] = 0;
        }
    }
    m4 = 0;
    D_00392754 = this;
    m6A60 = func_0010A638(D_00388A70, 0x3A98, 1, 0);
    m6A64 = 0;
    m8 = 0;
    m6B00 = 0;
    int k = 0;
    for (int i = 0; k < 8; i++) {
        k++;
        func_003331D0(buf1, D_0037A480, k);
        m18[i].a = func_001F0D78(buf1);
        func_003331D0(buf2, D_0037A498, k);
        m18[i].b = func_001F0D78(buf2);
        func_003331D0(buf3, D_0037A4A8, k);
        m18[i].c = func_001F0D78(buf3);
    }
    m3528 = 0;
    func_002C3778(this);
    mC = 0;
    m6A68 = 0;
    m78 = 0;
    m7C = 0;
}
