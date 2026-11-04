struct Box_002C0168 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Game_002C0168 {
    char pad[0xB4];
    float mB4;
};

extern "C" Game_002C0168* func_002C4970(int v);
extern "C" void func_002C49C0();

struct Ref_002C0168 {
    int m0;
    Game_002C0168* m4;
    Ref_002C0168(Game_002C0168* p) { m4 = p; }
};

class Ctx_002C0168 {
public:
    int m0;
    Ref_002C0168 m4;
    Ctx_002C0168() : m4(func_002C4970(0)) {}
    Ref_002C0168* GetRef() { return &m4; }
    bool Busy() { return GetRef()->m4->mB4 >= 1.0f; }
    virtual void Dummy();
    virtual ~Ctx_002C0168() { func_002C49C0(); }
};

struct Obj_002C0168;
extern "C" int func_002BFC50(Obj_002C0168* self, Box_002C0168* b, bool* out);
extern "C" bool func_002BFF80(Obj_002C0168* self, Box_002C0168* b, int a, int c, int keep, int check);
extern "C" int func_002BD7D8(Obj_002C0168* self, int v);
extern "C" void func_002C0E60(Obj_002C0168* self, int a, int b);
extern "C" void func_002C00F0(Obj_002C0168* self);

struct Obj_002C0168 {
    bool Drop(Box_002C0168* box, int n);
};

bool Obj_002C0168::Drop(Box_002C0168* box, int n)
{
    Box_002C0168 c = *box;
    bool out;
    int r = func_002BFC50(this, &c, &out);
    bool ok = true;
    c = *box;
    if (func_002BFF80(this, &c, box->y, r, n > 0, !out)) {
        Ctx_002C0168 ctx;
        if (func_002BD7D8(this, ctx.Busy())) {
            func_002C0E60(this, 0, 0);
        } else {
            func_002C00F0(this);
            ok = false;
            func_002BD7D8(this, 0);
        }
    } else {
        ok = false;
    }
    return ok;
}
