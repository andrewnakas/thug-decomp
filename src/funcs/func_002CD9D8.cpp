typedef int qword __attribute__((mode(TI)));

union Vec_002CD9D8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Box_002CD9D8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    signed char h;
    unsigned char d;
    unsigned char X() { return x; }
    unsigned char Z() { return z; }
};

struct Node_002CD9D8 {
    char pad0[0xC];
    Node_002CD9D8* mC;
};

struct Piece_002CD9D8 {
    char m0;
    signed char m1;
    char pad2[0x32];
    unsigned int m34;
};

struct Item_002CD9D8;

extern void* D_0039274C;
extern "C" void* func_002C0368();
extern "C" Node_002CD9D8* func_002BFA58(void* park, int x, int z);
extern "C" void* func_002BC5A0(Node_002CD9D8* n);
extern "C" Piece_002CD9D8* func_002BAB80(void* p);
extern "C" int func_002BAB90(Piece_002CD9D8* p);
extern "C" int func_002BAC50(Piece_002CD9D8* p, Box_002CD9D8* b);
extern "C" int func_002CD240(Item_002CD9D8* n, void* w);
extern "C" Vec_002CD9D8 func_002C02B0(void* a, Box_002CD9D8* c, Vec_002CD9D8* out);
extern "C" void* func_0029C320();
extern "C" int func_0029AB30(void* p, float a, float b, float c, float d);

struct Item_002CD9D8 {
    char pad0[0x18];
    Item_002CD9D8* m18;
};

struct Obj_002CD9D8 {
    unsigned char m0;
    Box_002CD9D8 m1;
    char pad7[5];
    Item_002CD9D8* mC;
    int m10;
    bool Place(Box_002CD9D8* b);
};

extern "C" int func_002CD5F0(Obj_002CD9D8* self, Piece_002CD9D8* p, int off);
extern "C" void func_002CD4D8(Obj_002CD9D8* self);

bool Obj_002CD9D8::Place(Box_002CD9D8* b)
{
    m1 = *b;
    void* park;
    int low = 0;
    park = func_002C0368();
    for (int x = b->X(); x < b->x + b->w; x++) {
        for (int z = b->Z(); z < b->z + b->d; z++) {
            for (Node_002CD9D8* n = func_002BFA58(park, x, z); n; n = n->mC) {
                Piece_002CD9D8* p = func_002BAB80(func_002BC5A0(n));
                int y = p->m1;
                switch (p->m34) {
                case 0x16C20A54:
                case 0x1F74467F:
                case 0x61C53AC2:
                case 0x66A8FEDB:
                case 0x88A69FF7:
                case 0x8FCB5BEE:
                case 0xF8CC6B78:
                case 0xFFA1AF61:
                    y++;
                    break;
                }
                low = low <= y ? low : y;
            }
        }
    }
    int off = -low;
    for (int x = b->X(); x < b->x + b->w; x++) {
        for (int z = b->Z(); z < b->z + b->d; z++) {
            for (Node_002CD9D8* n = func_002BFA58(park, x, z); n; n = n->mC) {
                Piece_002CD9D8* p = func_002BAB80(func_002BC5A0(n));
                if (func_002BAB90(p))
                    continue;
                if (!func_002BAC50(p, b))
                    continue;
                if (!func_002CD5F0(this, p, off)) {
                    func_002CD4D8(this);
                    return false;
                }
            }
        }
    }
    for (Item_002CD9D8* it = mC; it; it = it->m18) {
        if (!func_002CD240(it, D_0039274C)) {
            func_002CD4D8(this);
            return false;
        }
    }
    Vec_002CD9D8 pos;
    Vec_002CD9D8 size;
    pos = func_002C02B0(D_0039274C, b, &size);
    m10 = func_0029AB30(func_0029C320(), pos.f.x, pos.f.z, pos.f.x + size.f.x, pos.f.z + size.f.z);
    return true;
}
