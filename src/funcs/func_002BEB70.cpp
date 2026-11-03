struct Box_002BEB70 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002BEB70 {
    int m0;
    int m4;
    int m8;
};

struct Node_002BEB70 {
    char pad0[0xC];
    Node_002BEB70* mC;
};

struct Piece_002BEB70 {
    char pad0[0x8];
    unsigned int m8;
};

extern "C" void* func_002BF948(void* self, Box_002BEB70* b);
extern "C" void func_002BC630(List_002BEB70* l, void* r);
extern "C" void func_002BC640(List_002BEB70* l, int f);
extern "C" Node_002BEB70* func_002BC690(List_002BEB70* l);
extern "C" Piece_002BEB70* func_002BC5A0(void* n);
extern "C" void* func_002BAB80(void* p);
extern "C" int func_002BAC50(Piece_002BEB70* p, Box_002BEB70* b);
extern "C" void func_002BB700(void* p, void* arg, int c);

struct Obj_002BEB70 {
    void Apply(Box_002BEB70* box, void* arg);
};

void Obj_002BEB70::Apply(Box_002BEB70* box, void* arg)
{
    List_002BEB70 l;
    Box_002BEB70 b = *box;
    func_002BC630(&l, func_002BF948(this, &b));
    for (Node_002BEB70* n = func_002BC690(&l); n; n = n->mC) {
        Piece_002BEB70* p = func_002BC5A0(n);
        if (p && (p->m8 & 1) && func_002BAC50(p, box)) {
            func_002BB700(func_002BAB80(func_002BC5A0(n)), arg, 0);
        }
    }
    func_002BC640(&l, 2);
}
