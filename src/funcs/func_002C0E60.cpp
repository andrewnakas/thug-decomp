struct Node_002C0E60 {
    char pad[0xC];
    Node_002C0E60* mC;
};

struct Piece_002C0E60 {
    char pad[0x8];
    int m8;
};

struct Cur_002C0E60 {
    char pad[0x4C];
    int m4C;
};

extern "C" void* func_002BC5A0(Node_002C0E60* n);
extern "C" Piece_002C0E60* func_002BAB80(void* p);
extern "C" void func_002BB700(Piece_002C0E60* p, void* arg, int c);
extern "C" void func_002B84C8(void* p, int v);
extern "C" void func_002CC608(void* p, int v);

struct Obj_002C0E60 {
    void* m0;
    char pad4[0x80 - 0x4];
    Node_002C0E60* m80;
    char pad84[0x6B00 - 0x84];
    void* m6B00;
    void Refresh(void* arg, Cur_002C0E60* c);
};

void Obj_002C0E60::Refresh(void* arg, Cur_002C0E60* c)
{
    for (Node_002C0E60* n = m80; n; n = n->mC) {
        if (func_002BAB80(func_002BC5A0(n))->m8 & 0x1000)
            func_002BB700(func_002BAB80(func_002BC5A0(n)), arg, 1);
    }
    func_002B84C8(m0, 0);
    if (arg && c && c->m4C >= 0)
        func_002CC608(m6B00, c->m4C);
    else if (!arg)
        func_002B84C8(m0, 0);
}
