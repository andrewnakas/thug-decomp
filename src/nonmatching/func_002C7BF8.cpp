/* fuzzy: 93.8 */
/* sym: _vt$12Ctx_002C7BF8 = 0x00367170 */
struct Box_002C7BF8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002C7BF8 {
    int m0;
    int m4;
    int m8;
};

struct Game_002C7BF8 {
    char pad[0xB4];
    float mB4;
    bool IsFull() { return mB4 >= 1.0f; }
};

struct Board_002C7BF8;
struct Box_002C7BF8;

extern "C" Game_002C7BF8* func_002C4970(int v);
extern "C" void func_002C49C0();
extern "C" void* func_002BF5C0(Board_002C7BF8* b, Box_002C7BF8* box, int a, int c, int d);
extern "C" List_002C7BF8* func_002BC630(List_002C7BF8* l, void* r);
extern "C" void func_002BC640(List_002C7BF8* l, int f);
extern "C" void* func_002BC690(List_002C7BF8* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" Box_002C7BF8* func_002BAB80(void* p);
extern "C" void func_002BAA80(Box_002C7BF8* b);
extern "C" void* func_002C0640(Board_002C7BF8* b, Box_002C7BF8* box, void* out);
extern "C" void func_002C0BE0(Board_002C7BF8* b, void* p);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_002C0730(Board_002C7BF8* b, void* p);
extern "C" int func_002BD7D8(Board_002C7BF8* b, int v);
extern "C" void func_002C0E60(Board_002C7BF8* b, int a, void* p);
extern char D_00392830[];
extern char D_00392838[];

struct GRef_002C7BF8 {
    int m0;
    Game_002C7BF8* m4;
    GRef_002C7BF8(Game_002C7BF8* p) { m4 = p; }
};

class Ctx_002C7BF8 {
public:
    int m0;
    GRef_002C7BF8 m4;
    Ctx_002C7BF8() : m4(func_002C4970(0)) {}
    GRef_002C7BF8* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_002C7BF8() { func_002C49C0(); }
};

struct Board_002C7BF8 {
    void* Find(Box_002C7BF8 b) { return func_002BF5C0(this, &b, 0, 0, 0); }
};

struct BRef_002C7BF8 {
    int m0;
    Board_002C7BF8* m4;
};

struct Obj_002C7BF8 {
    int m0;
    BRef_002C7BF8 m4;
    char padC[4];
    Box_002C7BF8 m10;
    char pad16[0x80 - 0x16];
    Box_002C7BF8 m80[2];
    char pad8C_dummy[0];
    int m8C[2];
    int m94[2];
    int m9C[2];
    char mA4[0xC4 - 0xA4];
    int mC4;
    int mC8;
    int mCC;
    char padD0[4];
    unsigned int mD4;
    BRef_002C7BF8* GetRef() { return &m4; }
    int Pick();
};

int Obj_002C7BF8::Pick()
{
    Ctx_002C7BF8 ctx;
    if (ctx.GetRef()->m4->IsFull()) return 0;
    List_002C7BF8 l;
    Box_002C7BF8 b = m10;
    func_002BC630(&l, func_002BF5C0(GetRef()->m4, &b, 0, 0, 0));
    if (!l.m0) {
        func_002BC640(&l, 2);
        return 0;
    }
    Box_002C7BF8* pc = func_002BAB80(func_002BC5A0(func_002BC690(&l)));
    func_002BAA80(&m10);
    char out[16];
    if (func_002C0640(GetRef()->m4, &m10, out)) {
        if (mC8 != 1) goto fail;
        func_002BC640(&l, 2);
        return 0;
    }
    if (!pc) goto fail;
    void* p;
    if (mC8 == 1) {
        func_002C0BE0(GetRef()->m4, m80);
        p = m80;
    } else {
        mC8 = 0;
        p = m80;
    }
    {
        int i = mC8;
        b = *pc;
        m80[i] = b;
        m8C[i] = 0;
        m94[i] = 0;
        m9C[i] = 0;
        mC4 = 100;
        mC8 = i + 1;
        mCC = -1;
        if (i == 0) {
            if (mD4 >= 2) {
                func_003331D0(mA4, D_00392830, mD4);
            } else {
                *(int*)mA4 = *(int*)D_00392838;
            }
            mD4++;
        }
    }
    if (!func_002C0730(GetRef()->m4, p)) {
        mC8 = 0;
        goto fail;
    }
    func_002BD7D8(GetRef()->m4, 0);
    if (mC8 > 0) func_002C0E60(GetRef()->m4, 1, p);
    func_002BC640(&l, 2);
    return 1;
fail:
    func_002BC640(&l, 2);
    return 0;
}
