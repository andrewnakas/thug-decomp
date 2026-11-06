/* fuzzy: 55.3 */
struct Box_002BF260 {
    unsigned char x;
    signed char y;
    int GetY() const { return y; }
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" Box_002BF260* func_002BAA28(Box_002BF260* b, int x, int y, int z, int w, int h, int d);

struct RBox_002BF260 : Box_002BF260 {
    RBox_002BF260() { func_002BAA28(this, 0, 0, 0, 0, 0, 0); }
};

struct Rec_002BF260 {
    RBox_002BF260 boxes[2];
    int m0C[18];
};

struct Item_002BF260 {
    Box_002BF260 box;
    int m8;
    int mC;
    char pad10[0x34 - 0x10];
    int m34;
};

struct Info_002BF260 {
    int idx;
    int a;
    int key;
    int c;
    int flags;
    int has;
    Box_002BF260* pbox;
};

struct Node_002BF260 {
    char pad0[0x8];
    int m8;
};

struct Obj_002BF260;
extern "C" Rec_002BF260* func_002C0640(Obj_002BF260* o, Box_002BF260* b, Info_002BF260* info);
extern "C" void func_002C0BE0(Obj_002BF260* o, Rec_002BF260* r);
extern "C" unsigned char* func_002BAA48(Box_002BF260* b, int idx);
extern "C" void func_002BE958(Obj_002BF260* o, Item_002BF260* it, int f);
extern "C" void* func_002BE5F0(Obj_002BF260* o, int key, int* out);
extern "C" Node_002BF260* func_002BE6E0(Obj_002BF260* o, void* p, int a);
extern "C" void func_002BACC0(Node_002BF260* n, int v);
extern "C" void func_002BF008(Obj_002BF260* o, Box_002BF260* b, Node_002BF260* n);
extern "C" void func_002C0730(Obj_002BF260* o, Rec_002BF260* r);

struct Obj_002BF260 {
    Node_002BF260* Move(Item_002BF260* it, int dx, int dy, int dz);
};

Node_002BF260* Obj_002BF260::Move(Item_002BF260* it, int dx, int dy, int dz)
{
    Box_002BF260 b;
    Box_002BF260 b2;
    Info_002BF260 info;
    info.key = it->m34;
    info.c = it->mC;
    info.a = dz;
    info.flags = it->m8;
    b = it->box;
    Rec_002BF260* r = func_002C0640(this, &b, &info);
    Rec_002BF260 rec;
    info.has = 0;
    info.pbox = &b2;
    if (r) {
        info.has = 1;
        rec = *r;
        func_002C0BE0(this, r);
        *func_002BAA48(&rec.boxes[info.idx], 0) = rec.boxes[info.idx].x + dx;
        *func_002BAA48(&rec.boxes[info.idx], 1) = rec.boxes[info.idx].GetY() + dy;
        *func_002BAA48(&rec.boxes[info.idx], 2) = rec.boxes[info.idx].z + info.a;
    }
    func_002BE958(this, it, 0);
    *func_002BAA48(&b, 0) += dx;
    *func_002BAA48(&b, 1) = b.GetY() + dy;
    *func_002BAA48(&b, 2) += info.a;
    Node_002BF260* n = func_002BE6E0(this, func_002BE5F0(this, info.key, 0), 0);
    func_002BACC0(n, info.c);
    n->m8 = info.flags & ~4;
    b2 = b;
    func_002BF008(this, info.pbox, n);
    if (info.has) func_002C0730(this, &rec);
    return n;
}
