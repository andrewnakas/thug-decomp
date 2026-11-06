/* fuzzy: 82.6 */
/* nonmatch func_002C1600: best earlier draft (thug-claude-lane3/work/w53/p5/func_002C1600.fail), 114 of 242 words differ. */
struct Box_002C1600 {
    unsigned char x;
    signed char y;
    int GetY() const { return y; }
    int Top() const { return GetY() + h; }
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Child_002C1600 {
    unsigned char x;
    unsigned char y;
    int GetY() const { return y; }
    unsigned char z;
    unsigned char m3;
    unsigned char m4;
};

struct List_002C1600 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Cell_002C1600 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Piece_002C1600 {
    Box_002C1600 m0;
    char pad[0x30 - 6];
    unsigned int m30;
    int m34;
    virtual void* Get(unsigned int i);
};

struct Obj_002C1600;
static inline void Raise_002C1600(int& a, int b) { if (a < b) a = b; }
extern "C" Child_002C1600* func_002BB3B0(Piece_002C1600* self, unsigned int i);
extern "C" void* func_002B6CF8(void* n);
extern "C" void func_002BAA28(Box_002C1600* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002B6C58(void* t, Box_002C1600* b);
extern "C" unsigned char* func_002BAA48(Box_002C1600* b, int idx);
extern "C" void func_002BAA50(Box_002C1600* b);
extern "C" void* func_002BF5C0(Obj_002C1600* o, Box_002C1600* b, int a, int c, int d);
extern "C" List_002C1600* func_002BC630(List_002C1600* l, void* r);
extern "C" void func_002BC640(List_002C1600* l, int f);

struct Obj_002C1600 {
    char pad0[0x3538];
    Cell_002C1600** cells;
    void Mark(Piece_002C1600* p, int set);
};

void Obj_002C1600::Mark(Piece_002C1600* p, int set)
{
    for (unsigned int i = 0; i < p->m30; i++) {
        void* t = func_002B6CF8(p->Get(i));
        Child_002C1600* c = func_002BB3B0(p, i);
        if (!c->m4) continue;
        Box_002C1600 box;
        func_002BAA28(&box, 0, 0, 0, 0, 0, 0);
        func_002B6C58(t, &box);
        *func_002BAA48(&box, 0) = p->m0.x + c->x;
        *func_002BAA48(&box, 1) = p->m0.GetY() + c->GetY();
        *func_002BAA48(&box, 2) = p->m0.z + c->z;
        int x0 = box.x;
        int xe = x0 + box.w;
        int z0 = box.z;
        int d = box.d;
        for (int x = x0; x < xe; x++) {
            for (int z = z0; z < z0 + d; z++) {
                if (set) {
                    Raise_002C1600(cells[x][z].m0, box.GetY() + box.h);
                    if (cells[x][z].m0 >= 16) cells[x][z].m0 = 15;
                    if (cells[x][z].m0 < -16) cells[x][z].m0 = -16;
                } else {
                    Box_002C1600 b2 = box;
                    *func_002BAA48(&b2, 1) = box.GetY() + box.h;
                    func_002BAA50(&b2);
                    List_002C1600 l;
                    Box_002C1600 b3 = b2;
                    func_002BC630(&l, func_002BF5C0(this, &b3, 0, 0, 1));
                    if (l.m0 == 0) {
                        if (box.y < cells[x][z].m0) cells[x][z].m0 = box.y;
                    }
                    func_002BC640(&l, 2);
                }
                for (int y = box.y; y < box.y + box.h; y++) {
                    if (set) cells[x][z].m4 |= 1 << (y + 17);
                    else cells[x][z].m4 &= ~(1 << (y + 17));
                }
            }
        }
    }
}
