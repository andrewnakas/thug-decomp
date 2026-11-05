struct Box_002BFF80 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Node_002BFF80;
struct Obj_002BFF80;

extern "C" void func_002C20A0(Obj_002BFF80* o);
extern "C" void func_002BC5A8(Node_002BFF80* n);
extern "C" bool func_002C19C8(Obj_002BFF80* o, Box_002BFF80* b);
extern "C" bool func_002C1AA0(Obj_002BFF80* o, Box_002BFF80* b, int a, int c, int mode, Node_002BFF80** out);
extern "C" void func_002C1E58(Obj_002BFF80* o);
extern "C" void func_002C1F28(Obj_002BFF80* o, Node_002BFF80* n);
extern "C" void func_002C1FD8(Obj_002BFF80* o, Box_002BFF80* b);

struct Obj_002BFF80 {
    char pad0[0xC];
    Node_002BFF80* mC;
    int m10;
    int m14;
    bool Place(Box_002BFF80* box, int a, int b, int keep, int check);
};

bool Obj_002BFF80::Place(Box_002BFF80* box, int a, int b, int keep, int check)
{
    int mode = keep ? 6 : 4;
    if (check) mode |= 1;
    func_002C20A0(this);
    if (mC) func_002BC5A8(mC);
    mC = 0;
    m10 = 0;
    m14 = 0;
    Box_002BFF80 c;
    if (check) {
        c = *box;
        if (func_002C19C8(this, &c)) return false;
    }
    c = *box;
    bool fail = !func_002C1AA0(this, &c, a, b, mode, &mC);
    if (fail) {
        func_002C1E58(this);
        return false;
    }
    func_002C1F28(this, mC);
    if (!keep) {
        c = *box;
        func_002C1FD8(this, &c);
    }
    return true;
}
