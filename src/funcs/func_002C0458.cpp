struct Box_002C0458 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Game_002C0458 {
    char pad[0xB4];
    float mB4;
};

struct List_002C0458 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002C0458 {
    char pad0[0xC];
    Node_002C0458* mC;
};

struct Piece_002C0458 {
    char pad0[0x8];
    int m8;
};

extern "C" Game_002C0458* func_002C4970(int v);
extern "C" void func_002C49C0();

struct Ref_002C0458 {
    int m0;
    Game_002C0458* m4;
    Ref_002C0458(Game_002C0458* p) { m4 = p; }
};

class Ctx_002C0458 {
public:
    int m0;
    Ref_002C0458 m4;
    Ctx_002C0458() : m4(func_002C4970(0)) {}
    Ref_002C0458* GetRef() { return &m4; }
    bool Busy() { return GetRef()->m4->mB4 >= 1.0f; }
    virtual void Dummy();
    virtual ~Ctx_002C0458() { func_002C49C0(); }
};

struct Obj_002C0458 {
    bool Check(Box_002C0458* box, int flag);
};

extern "C" void* func_002BF948(Obj_002C0458* self, Box_002C0458* b);
extern "C" List_002C0458* func_002BC630(List_002C0458* l, void* r);
extern "C" void func_002BC640(List_002C0458* l, int f);
extern "C" Node_002C0458* func_002BC690(List_002C0458* l);
extern "C" void* func_002BC5A0(Node_002C0458* n);
extern "C" Piece_002C0458* func_002BAB80(void* p);
extern "C" int func_002BFC50(Obj_002C0458* self, Box_002C0458* b, int* out);
extern "C" bool func_002C03B8(Obj_002C0458* self, Box_002C0458* b);

bool Obj_002C0458::Check(Box_002C0458* box, int flag)
{
    Ctx_002C0458 ctx;
    if (ctx.Busy()) return false;
    List_002C0458 l;
    Box_002C0458 c = *box;
    int out;
    func_002BC630(&l, func_002BF948(this, &c));
    for (Node_002C0458* n = func_002BC690(&l); n; n = n->mC) {
        if (((func_002BAB80(func_002BC5A0(n))->m8 >> 3) & 1) == 0) {
            func_002BC640(&l, 2);
            return false;
        }
    }
    if (!flag) {
        c = *box;
        if (func_002BFC50(this, &c, &out) != box->y || !out) {
            func_002BC640(&l, 2);
            return false;
        }
    }
    c = *box;
    if (func_002C03B8(this, &c)) {
        func_002BC640(&l, 2);
        return false;
    }
    func_002BC640(&l, 2);
    return true;
}
