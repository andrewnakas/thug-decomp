struct Box_002BEE08 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Node_002BEE08 {
    char pad0[0xC];
    Node_002BEE08* mC;
};

struct Piece_002BEE08 {
    char pad0[0x8];
    unsigned int m8;
    char padC[0x24];
    unsigned short m30;
};

extern "C" Node_002BEE08* func_002BF5C0(void* self, Box_002BEE08* b, int a, int c, int d);
extern "C" void* func_002BC5A0(void* n);
extern "C" Piece_002BEE08* func_002BAB80(void* p);
extern "C" void func_002BE958(void* self, Piece_002BEE08* p, int f);
extern "C" void func_002BC5A8(Node_002BEE08* n);

struct Obj_002BEE08 {
    unsigned int Place(Box_002BEE08* box, int flags);
};

unsigned int Obj_002BEE08::Place(Box_002BEE08* box, int flags)
{
    unsigned short count = 0;
    unsigned short sum = 0;
    Box_002BEE08 b = *box;
    Node_002BEE08* list = func_002BF5C0(this, &b, 0, 0, (flags >> 1) & 1);
    for (Node_002BEE08* n = list; n; n = n->mC) {
        if (flags & 4) {
            if (func_002BAB80(func_002BC5A0(n))->m8 & 0x20) continue;
        }
        count++;
        sum += func_002BAB80(func_002BC5A0(n))->m30;
        func_002BE958(this, func_002BAB80(func_002BC5A0(n)), flags);
    }
    func_002BC5A8(list);
    return (count << 16) | sum;
}
