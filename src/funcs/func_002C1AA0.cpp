struct Box_002C1AA0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C1AA0(const Box_002C1AA0& o) { *this = o; }
    unsigned char X() const { return x; }
    unsigned char W() const { return w; }
    unsigned char Z() const { return z; }
    unsigned char D() const { return d; }
};

struct List_002C1AA0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002C1AA0 {
    char pad0[0xC];
    Node_002C1AA0* mC;
};

struct Piece_002C1AA0 {
    Box_002C1AA0 box;
    char pad6[0x2];
    int m8;
};

struct Cell_002C1AA0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Item_002C1AA0 {
    int m0;
    int m4;
    Piece_002C1AA0* m8;
    Item_002C1AA0* mC;
};

struct Obj_002C1AA0;
extern void* D_00388A70;
extern "C" char* func_002BAA48(Box_002C1AA0* b, int idx);
extern "C" void func_002BAA68(Box_002C1AA0* b);
extern "C" void func_002BAA50(Box_002C1AA0* b);
extern "C" void* func_002BF5C0(Obj_002C1AA0* o, Box_002C1AA0 b, int a, int c, int d);
extern "C" List_002C1AA0* func_002BC630(List_002C1AA0* l, void* r);
extern "C" void func_002BC640(List_002C1AA0* l, int f);
extern "C" Node_002C1AA0* func_002BC690(List_002C1AA0* l);
extern "C" void* func_002BC5A0(Node_002C1AA0* n);
extern "C" Piece_002C1AA0* func_002BAB80(void* p);
extern "C" int func_002B74E0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void* func_002C48E0(unsigned int size);
extern "C" void func_0010A9B0(void* p);

struct Obj_002C1AA0 {
    void* m0;
    char pad4[0x3534];
    Cell_002C1AA0** m3538;
    bool Fill(Box_002C1AA0 b, int v, int level, int flags, Item_002C1AA0** out);
};

bool Obj_002C1AA0::Fill(Box_002C1AA0 b, int v, int level, int flags, Item_002C1AA0** out)
{
    Box_002C1AA0 c = b;
    *func_002BAA48(&c, 1) = v;
    if (flags & 4) {
        func_002BAA68(&c);
    } else {
        func_002BAA50(&c);
    }
    int i;
    for (i = c.X(); i < c.X() + c.W(); i++) {
        int j;
        for (j = c.Z(); j < c.Z() + c.D(); j++) {
            if (m3538[i][j].m8 == 0) {
                int d;
                if (flags & 1) {
                    if (flags & 2) {
                        d = level - m3538[i][j].m0;
                    } else {
                        d = (m3538[i][j].m0 == level) ? -1 : 0;
                    }
                } else {
                    d = (flags & 2) ? 1 : -1;
                }
                m3538[i][j].m0 += d;
                m3538[i][j].mC = d;
                if ((unsigned int)(m3538[i][j].m0 + 16) >= 32) {
                    return false;
                }
            }
            m3538[i][j].m8 = 1;
        }
    }
    List_002C1AA0 l;
    func_002BC630(&l, func_002BF5C0(this, c, 0, 0, 1));
    for (Node_002C1AA0* n = func_002BC690(&l); n; n = n->mC) {
        Piece_002C1AA0* p = func_002BAB80(func_002BC5A0(n));
        Box_002C1AA0 pb = p->box;
        if ((p->m8 >> 3) & 1) continue;
        if (p->m8 & 0x20) continue;
        p->m8 |= 0x20;
        void* pool = D_00388A70;
        func_0010A950(pool, func_002B74E0(m0));
        Item_002C1AA0* it = (Item_002C1AA0*)func_002C48E0(16);
        func_0010A9B0(D_00388A70);
        it->mC = *out;
        it->m8 = p;
        *out = it;
        it->m4 = 0;
        if (flags & 1) {
            if (flags & 2) {
                it->m4 = level - pb.y;
            } else {
                it->m4 = (pb.y == level) ? -1 : 0;
            }
        } else {
            if (flags & 2) {
                it->m4 = 1;
            } else {
                it->m4 = -1;
            }
        }
        if (!Fill(pb, pb.y, level, flags & ~4, out)) {
            func_002BC640(&l, 2);
            return false;
        }
    }
    func_002BC640(&l, 2);
    return true;
}
