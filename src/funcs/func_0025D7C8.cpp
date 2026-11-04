extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" float func_001E5318(unsigned int name, int a);
extern "C" void func_00114D28(void* p, float t);
extern "C" unsigned long func_0010FA98();
extern "C" float func_0033CA90(unsigned long v);
extern "C" bool func_00107728(void* p);
extern "C" float func_00144DC0(void* p);
extern "C" bool func_001E53A0(unsigned int name, int a);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001E7138(void* s, const char* name, const char* v);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" double func_0033ECA8(float x);
extern int D_00388830;
extern char D_003757C8[];
extern char D_00390C18[];

struct Sub20_0025D7C8 {
    char pad[0x18];
    int m18;
};

struct Sub1C_0025D7C8 {
    char pad[0x20];
    int m20;
};

struct Item_0025D7C8 {
    char pad[0x1C];
    Sub1C_0025D7C8* m1C;
    Sub20_0025D7C8* m20;
};

struct List_0025D7C8 {
    char pad[0x28];
    Item_0025D7C8* m28[2];
};

struct Game_0025D7C8 {
    char pad[0x444];
    int m444;
};

extern List_0025D7C8* D_00390828;
extern Game_0025D7C8* D_0038FC78;

struct Obj_0025D7C8 {
    char pad[0xC];
    void* mC;
    char pad2[0xB64 - 0x10];
    int mB64;
    int mB68;
    float mB6C;
    float mB70;
    int mB74;
    unsigned long mB78;
    void Update(void* a);
};

extern "C" void func_0025DB90(Obj_0025D7C8* self, void* a);
extern "C" void func_0025DDA8(Obj_0025D7C8* self);
extern "C" void func_0025E0A8(Obj_0025D7C8* self);
extern "C" void func_0025D9F8(Obj_0025D7C8* self);

void Obj_0025D7C8::Update(void* a)
{
    if (!mB64) {
        mB64 = 1;
        func_001F0210(0xE794A164, 0, 0, 0, 0);
        func_00114D28(a, func_001E5318(0x99529205, 0));
        mB6C = 0.0f;
        mB78 = func_0010FA98();
    }
    mB6C = mB70;
    unsigned long dt = func_0010FA98() - mB78;
    int div = D_00388830;
    float f;
    if ((long)dt >= 0) {
        f = func_0033CA90(dt);
    } else {
        f = func_0033CA90((dt & 1) | (dt >> 1));
        f = f + f;
    }
    mB70 = f / (float)div;
    if (mB64 && mB70 != 0.0f) {
        Item_0025D7C8** pp = D_00390828->m28;
        for (int i = 0; i < 2; i++, pp++) {
            Item_0025D7C8* o = *pp;
            if (func_00107728(o->m20) && o->m20->m18 && (o->m1C->m20 & 0x40) && i == D_0038FC78->m444) {
                mB70 = func_00144DC0(mC);
                mB68 = 1;
            }
        }
    }
    func_0025DB90(this, a);
    func_0025DDA8(this);
    func_0025E0A8(this);
    func_0025D9F8(this);
    if (func_001E53A0(0x5ECC0073, 0)) {
        void* s = func_001E6978(func_001190D0(8));
        char buf[0x80];
        func_003331D0(buf, D_003757C8, func_0033ECA8(mB70));
        func_001E7138(s, D_00390C18, buf);
        func_001F0210(0xD9157174, s, 0, 0, 0);
        if (s) func_001E6AE8(s, 3);
    }
}
