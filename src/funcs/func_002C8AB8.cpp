typedef int qword __attribute__((mode(TI)));

union Vec_002C8AB8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Box_002C8AB8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C8AB8() {}
    Box_002C8AB8(const Box_002C8AB8& o) { *this = o; }
};

struct Piece_002C8AB8 {
    char pad0[0x14];
    Piece_002C8AB8* m14;
};

struct Obj_002C8AB8;
extern void* D_0039274C;
extern "C" int func_002C8A08(Obj_002C8AB8* p);
extern "C" Box_002C8AB8* func_002BAA28(Box_002C8AB8* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002C88F0(Obj_002C8AB8* self, Box_002C8AB8* out);
extern "C" Vec_002C8AB8 func_002C02B0(void* a, Box_002C8AB8* c, Vec_002C8AB8* out);
extern "C" void* func_0029C320();
extern "C" int func_0029AA78(void* p, float a, float b, float c, float d);
extern "C" int func_0029C020(void* p);
extern "C" int func_002C8C38(Obj_002C8AB8* self);
extern "C" void func_002C8990(Obj_002C8AB8* self);
extern "C" void* func_002CBBF0(unsigned int size);
extern "C" Piece_002C8AB8* func_002CD408(void* p);
extern "C" bool func_002CD9D8(Piece_002C8AB8* p, Box_002C8AB8 b);
extern "C" int func_002CDD58(Piece_002C8AB8* p);
extern "C" void func_002CD490(Piece_002C8AB8* p, int f);

struct Obj_002C8AB8 {
    char pad0[0x68];
    Piece_002C8AB8* m68;
    int Place();
};

int Obj_002C8AB8::Place()
{
    if (func_002C8A08(this)) return 0;
    Box_002C8AB8 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    func_002C88F0(this, &b);
    Vec_002C8AB8 pos;
    Vec_002C8AB8 size;
    pos = func_002C02B0(D_0039274C, &b, &size);
    int n = func_0029AA78(func_0029C320(), pos.f.x, pos.f.z, pos.f.x + size.f.x, pos.f.z + size.f.z);
    if (func_0029C020(func_0029C320()) < n) return 0;
    if (func_002C8C38(this) == 6) func_002C8990(this);
    Piece_002C8AB8* p = func_002CD408(func_002CBBF0(0x18));
    while (!func_002CD9D8(p, b)) {
        if (!m68) break;
        func_002C8990(this);
    }
    if (func_002CDD58(p)) {
        if (p) func_002CD490(p, 3);
        return 0;
    }
    p->m14 = m68;
    m68 = p;
    return 1;
}
