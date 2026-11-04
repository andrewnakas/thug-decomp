struct Box_002BF5C0 {
    unsigned char x;
    signed char y;
    int GetY() const { return y; }
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Child_002BF5C0 {
    unsigned char x;
    signed char y;
    unsigned char z;
};

struct List_002BF5C0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002BF5C0 {
    char pad0[0xC];
    Node_002BF5C0* mC;
};

struct Item_002BF5C0 {
    char pad0[0x8];
    int m8;
};

struct Piece_002BF5C0;

struct Filter_002BF5C0 {
    Box_002BF5C0 m0;
    char pad[0x30 - 6];
    unsigned int m30;
};

struct Obj_002BF5C0;

extern "C" Item_002BF5C0* func_002BC5A0(Node_002BF5C0* n);
extern "C" Piece_002BF5C0* func_002BAB80(void* p);
extern "C" bool func_002BBB40(Piece_002BF5C0* p, Box_002BF5C0* b, int deep);
extern "C" void func_002C24E0(Obj_002BF5C0* o, Item_002BF5C0* it, Node_002BF5C0** out);
extern "C" void func_002BC5E0(Node_002BF5C0* n);
extern "C" void func_002BACC0(Filter_002BF5C0* f, int a);
extern "C" unsigned char* func_002BAA48(Box_002BF5C0* b, int idx);
extern "C" Box_002BF5C0* func_002BAA28(Box_002BF5C0* b, unsigned char x, signed char y, unsigned char z,
                                        unsigned char w, unsigned char h, unsigned char d);
extern "C" List_002BF5C0* func_002BC630(List_002BF5C0* l, Node_002BF5C0* r);
extern "C" void func_002BC640(List_002BF5C0* l, int f);
extern "C" Node_002BF5C0* func_002BC690(List_002BF5C0* l);
extern "C" Child_002BF5C0* func_002BB3B0(Filter_002BF5C0* f, unsigned int i);

struct Obj_002BF5C0 {
    char pad0[0x98];
    Node_002BF5C0* m98[1][58];
    Node_002BF5C0* Query(Box_002BF5C0* box, int a, Filter_002BF5C0* filter, int mode);
};

Node_002BF5C0* Obj_002BF5C0::Query(Box_002BF5C0* box, int a, Filter_002BF5C0* filter, int mode)
{
    if (!filter) {
        Node_002BF5C0* result = 0;
        int xe = box->x + box->w;
        for (int x = box->x; x < xe; x++) {
            int ze = box->z + box->d;
            for (int z = box->z; z < ze; z++) {
                for (Node_002BF5C0* n = m98[x][z]; n; n = n->mC) {
                    if (mode && ((func_002BC5A0(n)->m8 >> 3) & 1)) continue;
                    Box_002BF5C0 c = *box;
                    if (func_002BBB40(func_002BAB80(func_002BC5A0(n)), &c, mode))
                        func_002C24E0(this, func_002BC5A0(n), &result);
                }
            }
        }
        func_002BC5E0(result);
        return result;
    }
    func_002BACC0(filter, a);
    *func_002BAA48(box, 3) = filter->m0.w;
    *func_002BAA48(box, 4) = filter->m0.h;
    *func_002BAA48(box, 5) = filter->m0.d;
    List_002BF5C0 l;
    Node_002BF5C0* result = 0;
    Box_002BF5C0 c = *box;
    func_002BC630(&l, Query(&c, 0, 0, 0));
    for (unsigned int i = 0; i < filter->m30; i++) {
        Child_002BF5C0* ch = func_002BB3B0(filter, i);
        func_002BAA28(&c, ch->x, ch->y, ch->z, 0, 0, 0);
        *func_002BAA48(&c, 0) += box->x;
        *func_002BAA48(&c, 1) += box->GetY();
        *func_002BAA48(&c, 2) += box->z;
        for (Node_002BF5C0* n = func_002BC690(&l); n; n = n->mC) {
            Box_002BF5C0 b2 = c;
            if (func_002BBB40(func_002BAB80(func_002BC5A0(n)), &b2, 0))
                func_002C24E0(this, func_002BC5A0(n), &result);
        }
    }
    func_002BACC0(filter, 0);
    func_002BC5E0(result);
    Node_002BF5C0* r = result;
    func_002BC640(&l, 2);
    return r;
}
