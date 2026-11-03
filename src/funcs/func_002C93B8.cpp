struct Box_002C93B8;
extern "C" void func_002BAA28(Box_002C93B8* b, int x, int y, int z, int w, int h, int d);

struct Box_002C93B8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C93B8() { func_002BAA28(this, 0, 0, 0, 0, 0, 0); }
    Box_002C93B8(const Box_002C93B8& o) { *this = o; }
};

struct Park_002C93B8 {
    char pad[0x352C];
    Box_002C93B8 m352C;
};

extern "C" Park_002C93B8* func_002C0368();
extern "C" void func_002C88F0(void* self, Box_002C93B8* out);
extern "C" void func_002CE120(void* p, void* self, Box_002C93B8* b);
extern "C" void func_002CE490(void* p);
struct Cursor_002C93B8;
extern "C" bool func_002C9260(Cursor_002C93B8* self, Box_002C93B8 b, int a, int c, int f);
extern "C" int func_002BFC50(void* park, Box_002C93B8 b, int* out);

struct Cursor_002C93B8 {
    int m0;
    int m4;
    void* m8;
    void* mC;
    Box_002C93B8 m10;
    char pad16[0x54 - 0x16];
    unsigned char m54;
    char pad55[0x64 - 0x55];
    int m64;
    char pad68[4];
    void* m6C;
    char pad70[0x7C - 0x70];
    int m7C;
    bool Try(int a);
};

bool Cursor_002C93B8::Try(int a)
{
    Box_002C93B8 b;
    switch (m7C) {
    case 4:
        if (m54) func_002C88F0(this, &b);
        else b = m10;
        break;
    case 5:
        if (m6C) func_002CE120(m6C, this, &b);
        break;
    default:
        b = m10;
        break;
    }
    Box_002C93B8 pb = func_002C0368()->m352C;
    if (pb.w < b.w) return false;
    if (pb.d < b.d) return false;
    int out;
    int r = func_002BFC50(m8, b, &out);
    if (m7C == 5 && m6C) func_002CE490(m6C);
    bool ok = func_002C9260(this, b, r, a, out);
    if (m7C == 4) m64 = 0;
    return ok;
}
