struct Box_002C1298 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Node_002C1298;

struct Piece_002C1298 {
    char pad0[0x8];
    int m8;
    char padC[0x34 - 0xC];
    int m34;
};

struct Info_002C1298 {
    char pad0[0x30];
    int m30;
};

struct Item_002C1298 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
};

struct Keys_002C1298 {
    int a;
    int b;
    int c;
};

struct Cell_002C1298 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Saved_002C1298 {
    int key;
    Box_002C1298 box;
};

extern "C" Box_002C1298* func_002BAA28(Box_002C1298* b, unsigned char x, signed char y, unsigned char z,
                                        unsigned char w, unsigned char h, unsigned char d);
extern "C" Node_002C1298* func_002BF5C0(void* self, Box_002C1298* b, int a, int c, int d);
extern "C" Piece_002C1298* func_002BC5A0(Node_002C1298* n);
extern "C" void func_002BC5A8(Node_002C1298* n);
extern "C" Info_002C1298* func_002BE5F0(void* self, int key, int* out);
extern "C" void func_001325A0();
extern Saved_002C1298* D_003942CC;

struct Obj_002C1298 {
    char pad0[0x18];
    Keys_002C1298 m18[1];
    char pad24[0x78 - 0x24];
    int m78;
    Saved_002C1298* m7C;
    char pad80[0x3538 - 0x80];
    Cell_002C1298** m3538;
    void Apply(Item_002C1298* it);
};

void Obj_002C1298::Apply(Item_002C1298* it)
{
    int key;
    if (it->mC & 1) {
        if (it->mC & 2) {
            key = m18[it->m10].a;
        } else {
            key = m18[it->m10].b;
        }
    } else {
        if (!(it->mC & 2)) return;
        key = m18[it->m10].c;
    }
    int mask = 1 << (it->m4 + 17);
    if (m3538[it->m0][it->m8].m4 & mask) return;
    Box_002C1298 b;
    func_002BAA28(&b, it->m0, it->m4, it->m8, 1, 1, 1);
    Box_002C1298 b2 = b;
    Node_002C1298* n = func_002BF5C0(this, &b2, 0, 0, 0);
    if (n) {
        if (func_002BC5A0(n)->m34 == key) {
            func_002BC5A0(n)->m8 &= ~0x10;
            func_002BC5A8(n);
            return;
        }
        func_002BC5A8(n);
    }
    if (it->m20 == 0) {
        if (!m7C) {
            func_001325A0();
            m7C = D_003942CC;
        }
        m7C[m78].key = key;
        func_002BAA28(&b2, it->m0, it->m4, it->m8, 0, 0, 0);
        m7C[m78].box = b2;
        m78++;
    } else {
        it->m28 += func_002BE5F0(this, key, 0)->m30;
    }
    it->m24++;
}
