/* fuzzy: 76.5 */
/* sym: _vt$12Ctx_002C9260 = 0x00367170 */
struct Box_002C9260 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C9260(int a, int b, int c, int e, int f, int g);
};

struct Game_002C9260 {
    char pad[0xB4];
    float mB4;
};

extern "C" Game_002C9260* func_002C4970(int v);
extern "C" void func_002C49C0();

struct Ctx_002C9260 {
    int m0;
    int m4;
    Game_002C9260* m8;
    Ctx_002C9260() { m8 = func_002C4970(0); }
    virtual void Dummy();
    virtual ~Ctx_002C9260() { func_002C49C0(); }
    Game_002C9260* Get() { return m8; }
};

struct Park_002C9260;

struct Sub_002C9260 {
    int m0;
    Park_002C9260* m4;
};

struct Obj_002C9260;
extern "C" int func_002BFF80(Park_002C9260* p, Box_002C9260 b, int y, int a, int b2, int c);
extern "C" void func_002C98B8(Obj_002C9260* o, int a, int b);
extern "C" int func_002BD7D8(Park_002C9260* p, int v);
extern "C" void func_002C0E60(Park_002C9260* p, int a, int b);
extern "C" void func_002C00F0(Park_002C9260* p);

struct Obj_002C9260 {
    int m0;
    Sub_002C9260 m4;
    bool Place(Box_002C9260* box, int a, int b, bool c);
};

bool Obj_002C9260::Place(Box_002C9260* box, int a, int b, bool c)
{
    if (box->w >= 11 || box->d >= 11)
        return false;
    Sub_002C9260* s = &m4;
    bool ok = true;
    if (func_002BFF80(s->m4, *box, box->y, a, b > 0, !c)) {
        func_002C98B8(this, 0, 0);
        Ctx_002C9260 ctx;
        if (func_002BD7D8(s->m4, ctx.Get()->mB4 >= 1.0f)) {
            func_002C0E60(s->m4, 0, 0);
        } else {
            func_002C00F0(s->m4);
            ok = false;
            func_002BD7D8(s->m4, 0);
        }
    } else {
        ok = false;
    }
    return ok;
}
