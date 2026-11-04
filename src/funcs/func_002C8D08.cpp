struct Box_002C8D08 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C8D08() {}
    Box_002C8D08(const Box_002C8D08& o) { *this = o; }
};

struct Board_002C8D08;

struct Sub_002C8D08 {
    int m0;
    Board_002C8D08* m4;
    Board_002C8D08* Get() { return m4; }
};

struct Obj_002C8D08;
extern "C" Box_002C8D08* func_002BAA28(Box_002C8D08* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002C88F0(Obj_002C8D08* o, Box_002C8D08* b);
extern "C" void func_002BEB70(Board_002C8D08* p, Box_002C8D08 b, int f);

struct Obj_002C8D08 {
    int m0;
    Sub_002C8D08 m4;
    char padC[0x10 - 0xC];
    Box_002C8D08 m10;
    char pad16[0x54 - 0x16];
    unsigned char m54;
    char pad55[0x5B - 0x55];
    Box_002C8D08 m5B;
    char pad61[0x64 - 0x61];
    int m64;
    void Update();
    Box_002C8D08& Cur() { return m10; }
    Box_002C8D08& Last() { return m5B; }
};

void Obj_002C8D08::Update()
{
    unsigned char st = m54;
    if (st == 0) return;
    if (st != 1) return;
    if (!m64) {
        Box_002C8D08 b;
        func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
        func_002C88F0(this, &b);
        func_002BEB70(m4.Get(), b, 1);
        m64 = st;
        return;
    }
    if (Cur().x == Last().x && Cur().z == Last().z) return;
    Box_002C8D08 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    func_002C88F0(this, &b);
    func_002BEB70(m4.Get(), b, 0);
    Last() = Cur();
    func_002C88F0(this, &b);
    func_002BEB70(m4.Get(), b, 1);
}
