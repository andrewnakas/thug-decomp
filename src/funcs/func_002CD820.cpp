struct Piece_002CD820 {
    int m0;
    int m4;
    int m8;
    bool F8() { return (m8 & 8) != 0; }
};

struct Node_002CD820 {
    int m0;
    Piece_002CD820* m4;
    unsigned char m8;
    signed char m9;
    unsigned char mA;
    char padB;
    int mC;
    unsigned char m10;
    unsigned char m11;
    char pad12[6];
    Node_002CD820* m18;
};

struct Obj_002CD820;

extern "C" void* func_002CE5C8(unsigned int size);
extern "C" Node_002CD820* func_002CC8A8(void* p);
extern "C" int func_002C4750();
extern "C" int func_002C4770();
extern "C" void func_002CD5A0(Obj_002CD820* o, unsigned char a, unsigned char b);

struct Obj_002CD820 {
    char pad0[0xC];
    Node_002CD820* mC;
    bool AddFloor(int x, int y, int z);
};

bool Obj_002CD820::AddFloor(int x, int y, int z)
{
    for (Node_002CD820* n = mC; n; n = n->m18) {
        if (n->m4 && !n->m4->F8() && x >= n->m8 && x < n->m8 + n->m10 && z >= n->mA && z < n->mA + n->m11)
            return true;
    }
    for (Node_002CD820* n = mC; n; n = n->m18) {
        if (!n->m4 && x >= n->m8 && x < n->m8 + n->m10 && z >= n->mA && z < n->mA + n->m11) {
            if (y >= n->m9) n->m9 = y;
            return true;
        }
    }
    if (func_002C4750() == func_002C4770())
        return false;
    Node_002CD820* n = func_002CC8A8(func_002CE5C8(0x1C));
    n->m9 = y;
    n->m4 = 0;
    n->m8 = x;
    n->mA = z;
    n->m10 = 1;
    n->m11 = 1;
    func_002CD5A0(this, x, z);
    n->m18 = mC;
    mC = n;
    return true;
}
