struct Box_002C70D0;
extern "C" void func_002BAA28(Box_002C70D0* b, int x, int y, int z, int w, int h, int d);

struct Box_002C70D0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C70D0() { func_002BAA28(this, 0, 0, 0, 0, 0, 0); }
};

struct Vec_002C70D0 {
    float x, y, z, w;
    Vec_002C70D0() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Opt_002C70D0 {
    int m0;
    int m4;
};

struct Item_002C70D0 {
    int m0;
    Opt_002C70D0 opts[40];
    int pad144;
    int m148;
    int m14C;
};

struct Park_002C70D0;

extern "C" Park_002C70D0* func_002BA990(int v);
extern "C" Item_002C70D0* func_002C0370(Park_002C70D0* b, int idx, void* p);
extern "C" void func_002C9C18(void* self, int v);
extern void* D_00392824;
extern char D_0037AE48[];

struct Ref_002C70D0 {
    int m0;
    Park_002C70D0* m4;
};

struct Base_002C70D0 {
    int m0;
    Ref_002C70D0 m4;
    void* mC;
    Base_002C70D0() { mC = D_0037AE48; m4.m4 = func_002BA990(0); }
};

class Cursor_002C70D0 : public Base_002C70D0 {
public:
    Box_002C70D0 m10;
    float m18;
    int m1C;
    Vec_002C70D0 m20;
    Vec_002C70D0 m30;
    int m40;
    int m44;
    int m48;
    int m4C;
    void* m50;
    unsigned char m54;
    Box_002C70D0 m55[2];
    int m64;
    int m68;
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    Box_002C70D0 m80[2];
    char pad8C[0xC8 - 0x8C];
    int mC8;
    int mCC;
    int mD0;
    int mD4;
    Ref_002C70D0* GetRef() { return &m4; }
    Cursor_002C70D0();
};

Cursor_002C70D0::Cursor_002C70D0() : m44(0), m48(0), m4C(0), m50(0)
{
    m54 = 0;
    m18 = 1.0f;
    m64 = 0;
    m68 = 0;
    m6C = 0;
    m44 = 0;
    m74 = 0;
    m78 = 0;
    mC8 = 0;
    mD0 = 0;
    m7C = 0;
    Item_002C70D0* it = func_002C0370(GetRef()->m4, 0, &m78);
    func_002C9C18(this, it->opts[it->m14C].m4);
    mD4 = 1;
    D_00392824 = this;
}
