struct Box_002C19C8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002C19C8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002C19C8 {
    char pad0[0xC];
    Node_002C19C8* mC;
};

struct Piece_002C19C8 {
    char pad0[0x8];
    int m8;
};

struct Obj_002C19C8;
extern "C" void func_002BAA68(Box_002C19C8* b);
extern "C" void* func_002BF5C0(Obj_002C19C8* o, Box_002C19C8* b, int a, int c, int d);
extern "C" List_002C19C8* func_002BC630(List_002C19C8* l, void* r);
extern "C" void func_002BC640(List_002C19C8* l, int f);
extern "C" Node_002C19C8* func_002BC690(List_002C19C8* l);
extern "C" void* func_002BC5A0(Node_002C19C8* n);
extern "C" Piece_002C19C8* func_002BAB80(void* p);

struct Obj_002C19C8 {
    bool HasBlocker(Box_002C19C8* b);
};

bool Obj_002C19C8::HasBlocker(Box_002C19C8* b)
{
    func_002BAA68(b);
    List_002C19C8 l;
    Box_002C19C8 c = *b;
    func_002BC630(&l, func_002BF5C0(this, &c, 0, 0, 1));
    for (Node_002C19C8* n = func_002BC690(&l); n; n = n->mC) {
        if (func_002BAB80(func_002BC5A0(n))->m8 & 0x4000) {
            func_002BC640(&l, 2);
            return true;
        }
    }
    func_002BC640(&l, 2);
    return false;
}
