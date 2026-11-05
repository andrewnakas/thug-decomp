struct Box_002BFD50 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    unsigned char GetX() { return x; }
    unsigned char GetZ() { return z; }
    unsigned char GetW() { return w; }
    unsigned char GetD() { return d; }
};

struct List_002BFD50 {
    int m0;
    int m4;
    int m8;
};

struct Node_002BFD50 {
    char pad0[0xC];
    Node_002BFD50* mC;
};

struct Piece_002BFD50 {
    Box_002BFD50 box;
    char pad6[2];
    int m8;
};

struct Cell_002BFD50 {
    int val;
    int pad[3];
};

extern "C" void* func_002BF948(void* self, Box_002BFD50* b);
extern "C" void func_002BC630(List_002BFD50* l, void* r);
extern "C" void func_002BC640(List_002BFD50* l, int f);
extern "C" Node_002BFD50* func_002BC690(List_002BFD50* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" Piece_002BFD50* func_002BAB80(void* p);
extern "C" void func_002BF260(void* self, Piece_002BFD50* p, int a, int b, int c);
extern "C" void func_002BD7D8(void* p, int v);

struct Obj_002BFD50 {
    char pad0[0x3538];
    Cell_002BFD50** cells;
    char pad353C[0x6A64 - 0x353C];
    int m6A64;
    void Remove(Box_002BFD50* box);
};

void Obj_002BFD50::Remove(Box_002BFD50* box)
{
    List_002BFD50 l;
    {
        Box_002BFD50 b = *box;
        func_002BC630(&l, func_002BF948(this, &b));
    }
    for (Node_002BFD50* n = func_002BC690(&l); n; n = n->mC) {
        Piece_002BFD50* p = func_002BAB80(func_002BC5A0(n));
        if ((p->m8 >> 3) & 1) continue;
        Box_002BFD50 c = p->box;
        func_002BF260(this, p, 0, -c.y, 0);
        for (int x = c.GetX(); x < c.GetX() + c.GetW(); x++) {
            for (int z = c.GetZ(); z < c.GetZ() + c.GetD(); z++) {
                cells[x][z].val = 0;
            }
        }
    }
    for (int x = box->GetX(); x < box->GetX() + box->GetW(); x++) {
        for (int z = box->GetZ(); z < box->GetZ() + box->GetD(); z++) {
            cells[x][z].val = 0;
        }
    }
    m6A64 &= ~5;
    func_002BD7D8(this, 0);
    func_002BC640(&l, 2);
}
