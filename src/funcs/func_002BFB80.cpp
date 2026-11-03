struct Box_002BFB80 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    int Area() const { return w * d; }
};

struct Stats_002BFB80 {
    int m0;
    int m4;
    int m8;
    int mC;
    int pad[8];
};

extern char D_0037A5A8[];
extern char D_0037A5B8[];
extern char D_0037A5D0[];
extern "C" int func_002B73B8(void* p, char* name);
extern "C" void func_002B74F0(Stats_002BFB80* out, void* p, int a);

struct Obj_002BFB80 {
    void* m0;
    char pad4[0x90];
    int m94;
    char pad98[0x352C - 0x98];
    Box_002BFB80 m352C;
    bool CanAfford(Box_002BFB80* b);
};

bool Obj_002BFB80::CanAfford(Box_002BFB80* b)
{
    int cur = m352C.Area();
    int diff = b->Area() - cur;
    if (func_002B73B8(m0, D_0037A5A8) - m94 < diff) return false;
    int c0 = diff * func_002B73B8(m0, D_0037A5B8);
    int c1 = diff * func_002B73B8(m0, D_0037A5D0);
    Stats_002BFB80 st;
    func_002B74F0(&st, m0, 0);
    if (st.m4 < c0) return false;
    return st.mC >= c1;
}
