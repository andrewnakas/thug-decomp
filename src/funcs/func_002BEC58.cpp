typedef int qword __attribute__((mode(TI)));

union Vec_002BEC58 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Box_002BEC58 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002BEC58 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002BEC58 {
    char pad0[0xC];
    Node_002BEC58* mC;
};

struct Piece_002BEC58 {
    char pad0[0x8];
    int m8;
};

extern void* D_0039274C;
extern "C" void* func_002BF948(void* self, Box_002BEC58* b);
extern "C" List_002BEC58* func_002BC630(List_002BEC58* l, void* r);
extern "C" void func_002BC640(List_002BEC58* l, int f);
extern "C" Node_002BEC58* func_002BC690(List_002BEC58* l);
extern "C" void* func_002BC5A0(Node_002BEC58* n);
extern "C" Piece_002BEC58* func_002BAB80(void* p);
extern "C" int func_002BAB90(Piece_002BEC58* p);
extern "C" int func_002BAC50(Piece_002BEC58* p, Box_002BEC58* b);
extern "C" void func_002BE958(void* self, Piece_002BEC58* p, int f);
extern "C" Vec_002BEC58 func_002C02B0(void* a, Box_002BEC58* c, Vec_002BEC58* out);
extern "C" void* func_0029C320();
extern "C" void func_0029A8C8(void* p, int v, float a, float b, float c, float d);
extern "C" void func_002BD7D8(void* p, int v);

struct Obj_002BEC58 {
    bool Select(Box_002BEC58* box, int a, int b);
};

bool Obj_002BEC58::Select(Box_002BEC58* box, int a, int b)
{
    List_002BEC58 l;
    Box_002BEC58 c = *box;
    int any = 0;
    func_002BC630(&l, func_002BF948(this, &c));
    for (Node_002BEC58* n = func_002BC690(&l); n; n = n->mC) {
        Piece_002BEC58* p = func_002BAB80(func_002BC5A0(n));
        if ((p->m8 >> 3) & 1) continue;
        if (a && func_002BAB90(p)) continue;
        if (b && !func_002BAC50(p, box)) continue;
        func_002BE958(this, p, 1);
        any = 1;
    }
    Vec_002BEC58 pos;
    Vec_002BEC58 size;
    pos = func_002C02B0(D_0039274C, box, &size);
    func_0029A8C8(func_0029C320(), 1, pos.f.x, pos.f.z, pos.f.x + size.f.x, pos.f.z + size.f.z);
    if (any) {
        func_002BD7D8(this, 0);
        func_002BC640(&l, 2);
        return true;
    }
    func_002BC640(&l, 2);
    return false;
}
