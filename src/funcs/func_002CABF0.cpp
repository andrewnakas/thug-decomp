struct Box_002CABF0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002CABF0() {}
    Box_002CABF0(const Box_002CABF0& o) { *this = o; }
};

struct Park_002CABF0 {
    char pad[0x352C];
    Box_002CABF0 m352C;
};

extern char D_00392898[];
extern char D_003928A0[];
extern char D_003928A8[];
extern char D_003928B0[];
extern "C" Park_002CABF0* func_002C0368();
extern "C" int func_001E7E58(void* params, char* name, int* out, int a);
extern "C" unsigned char* func_002BAA48(Box_002CABF0* b, int idx);

Box_002CABF0 func_002CABF0(void* params)
{
    Box_002CABF0 b = func_002C0368()->m352C;
    int w = b.w;
    int d = b.d;
    func_001E7E58(params, D_00392898, &w, 0);
    func_001E7E58(params, D_003928A0, &d, 0);
    int dw = w - b.w;
    int dd = d - b.d;
    if (func_001E7E58(params, D_003928A8, &dw, 0)) w = b.w + dw;
    if (func_001E7E58(params, D_003928B0, &dd, 0)) d = b.d + dd;
    *func_002BAA48(&b, 0) = *func_002BAA48(&b, 0) - dw / 2;
    *func_002BAA48(&b, 2) = *func_002BAA48(&b, 2) - dd / 2;
    *func_002BAA48(&b, 3) = w;
    *func_002BAA48(&b, 5) = d;
    return b;
}
