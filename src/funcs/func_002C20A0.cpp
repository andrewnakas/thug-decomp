struct Box_002C20A0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    unsigned char X() const { return x; }
    unsigned char W() const { return w; }
    unsigned char Z() const { return z; }
    unsigned char D() const { return d; }
};

struct Cell_002C20A0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002C20A0 {
    char pad0[0xC];
    Node_002C20A0* mC;
};

struct Piece_002C20A0 {
    char pad0[0x8];
    int m8;
};

extern "C" void* func_002BC5A0(Node_002C20A0* n);
extern "C" Piece_002C20A0* func_002BAB80(void* p);

struct Obj_002C20A0 {
    char pad0[0x80];
    Node_002C20A0* m80;
    char pad84[0x3532 - 0x84];
    Box_002C20A0 m3532;
    Cell_002C20A0** m3538;
    Box_002C20A0* GetBox() { return &m3532; }
    void Reset();
};

void Obj_002C20A0::Reset()
{
    for (int i = GetBox()->X(); i < GetBox()->X() + GetBox()->W(); i++) {
        for (int j = GetBox()->Z(); j < GetBox()->Z() + GetBox()->D(); j++) {
            m3538[i][j].m8 = 0;
            m3538[i][j].mC = 0;
        }
    }
    for (Node_002C20A0* n = m80; n; n = n->mC) {
        func_002BAB80(func_002BC5A0(n))->m8 &= ~0x20;
    }
}
