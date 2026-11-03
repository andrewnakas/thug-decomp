struct Box_002C8A08 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Game_002C8A08;

extern "C" void func_002BAA28(Box_002C8A08* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002C88F0(void* self, Box_002C8A08* out);
extern "C" Game_002C8A08* func_002C4970(int v);
extern "C" void func_002C49C0();
extern "C" int func_002C6A28(Game_002C8A08* g, int w, int d);

struct Ref_002C8A08 {
    int m0;
    Game_002C8A08* m4;
    Ref_002C8A08(Game_002C8A08* p) { m4 = p; }
};

class Ctx_002C8A08 {
public:
    int m0;
    Ref_002C8A08 m4;
    Ctx_002C8A08() : m4(func_002C4970(0)) {}
    Ref_002C8A08* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_002C8A08() { func_002C49C0(); }
};

struct Obj_002C8A08 {
    int CanPlace();
};

int Obj_002C8A08::CanPlace()
{
    Box_002C8A08 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    func_002C88F0(this, &b);
    if (b.w < 11 && b.d < 11) {
        Ctx_002C8A08 ctx;
        if (func_002C6A28(ctx.m4.m4, b.w, b.d)) return 0;
    }
    return 1;
}
