struct Box_002C8EA0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002C8EA0 {
    int m0;
    int m4;
    int m8;
};

struct Node_002C8EA0 {
    char pad0[0xC];
    Node_002C8EA0* mC;
};

extern "C" void func_002CE080(void* p, void* self, void* arg);
extern "C" void* func_002BF5C0(void* b, Box_002C8EA0* box, int a, int c, int d);
extern "C" List_002C8EA0* func_002BC630(List_002C8EA0* l, void* r);
extern "C" void func_002BC640(List_002C8EA0* l, int f);
extern "C" Node_002C8EA0* func_002BC690(List_002C8EA0* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" void* func_002BAB80(void* p);
extern "C" void func_002BB700(void* p, void* arg, int c);

struct Obj_002C8EA0 {
    char pad0[0x8];
    void* m8;
    char padC[0x4];
    Box_002C8EA0 m10;
    char pad16[0x6C - 0x16];
    void* m6C;
    char pad70[0xC];
    int m7C;
    void Apply(void* arg);
};

void Obj_002C8EA0::Apply(void* arg)
{
    if (m7C == 5 && m6C) {
        func_002CE080(m6C, this, arg);
        return;
    }
    List_002C8EA0 l;
    Box_002C8EA0 b = m10;
    func_002BC630(&l, func_002BF5C0(m8, &b, 0, 0, 0));
    if (l.m0 == 0) {
        func_002BC640(&l, 2);
        return;
    }
    for (Node_002C8EA0* n = func_002BC690(&l); n; n = n->mC) {
        func_002BB700(func_002BAB80(func_002BC5A0(n)), arg, 0);
    }
    func_002BC640(&l, 2);
}
