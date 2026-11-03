extern "C" void* func_002BC5A0(void* n);

struct Box_002C1F28 {
    signed char b[6];
};

extern "C" Box_002C1F28* func_002BAB80(void* p);
extern "C" void func_002C1FD8(void* self, Box_002C1F28* b);
extern "C" int func_002BF260(void* self, Box_002C1F28* p, int a, int b, int c);

struct Node_002C1F28 {
    char pad0[0x4];
    int m4;
    int m8;
    Node_002C1F28* mC;
};

struct Obj_002C1F28 {
    void Place(Node_002C1F28* n);
};

void Obj_002C1F28::Place(Node_002C1F28* n)
{
    for (; n; n = n->mC) {
        Box_002C1F28* p = func_002BAB80(func_002BC5A0(n));
        if (n->m4 < 0) {
            Box_002C1F28 b = *p;
            func_002C1FD8(this, &b);
        }
        n->m8 = func_002BF260(this, p, 0, n->m4, 0);
    }
}
