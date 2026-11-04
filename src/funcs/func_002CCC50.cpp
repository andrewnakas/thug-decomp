struct Box_002CCC50 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Piece_002CCC50 {
    char pad0[0x8];
    int m8;
};

struct Info_002CCC50 {
    char pad[0x44];
    int m44;
};

struct Obj_002CCC50 {
    int m0;
    Piece_002CCC50* m4;
    char m8;
    signed char m9;
    char padA[2];
    int mC;
    void Place(unsigned char a, int dy, unsigned char b, Info_002CCC50* info);
};

extern "C" void func_002BAA28(Box_002CCC50* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002CC970(Obj_002CCC50* o, Box_002CCC50* c, int a, int b, Info_002CCC50* d);
extern "C" void* func_002C0368();
extern "C" void func_002C0168(void* g, Box_002CCC50* b, int f);
extern "C" int func_002BFC50(void* g, Box_002CCC50* b, int* out);
extern "C" void* func_002BE6E0(void* g, Piece_002CCC50* p, int a);
extern "C" void func_002BACC0(void* p, int v);
extern "C" void func_002BF008(void* g, Box_002CCC50* b, void* r);

void Obj_002CCC50::Place(unsigned char a, int dy, unsigned char b, Info_002CCC50* info)
{
    if (m4 && ((m4->m8 >> 3) & 1)) return;
    int tries = 0;
    Box_002CCC50 c;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    func_002CC970(this, &c, a, b, info);
    int y = m9 + dy;
    if (y >= 16) y = 15;
    signed char sy = y;
    unsigned char cz = c.z; unsigned char cx = c.x;
    c.z = cz; c.x = cx; c.y = sy;
    void* g = func_002C0368();
    Box_002CCC50 t;
    int out;
    for (;;) {
        out = 0;
        t = c;
        int h = func_002BFC50(g, &t, &out);
        if (y < h) break;
        if (tries >= 41) break;
        if (out && h == y) break;
        t = c;
        func_002C0168(g, &t, 1);
        tries++;
    }
    if (!m4) return;
    void* v = func_002BE6E0(g, m4, 0);
    int r = info->m44;
    func_002BACC0(v, (mC + r) & 3);
    t = c;
    func_002BF008(g, &t, v);
}
