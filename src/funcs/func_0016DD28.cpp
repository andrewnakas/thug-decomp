struct Mat_0016DD28 {
    char pad0[0x50];
    int m50;
    void* m54;
};

struct Node_0016DD28 {
    char pad0[0x1C];
    unsigned int m1C;
    Node_0016DD28* m20;
    int m24;
    Node_0016DD28* m28;
    void* m2C;
};

extern unsigned int D_00394098;
extern void* D_0039427C;
extern Node_0016DD28* D_0038BCD4;

extern "C" Mat_0016DD28* func_00167448(Mat_0016DD28* m);
extern "C" void func_00167F00(Mat_0016DD28* m);
extern "C" void func_0016FFE8(Node_0016DD28* n, Mat_0016DD28* m, int flags);
extern "C" void func_001617A0(void* p);
extern "C" void func_0016DED8(Node_0016DD28* n, Mat_0016DD28* m, int flags);
extern "C" Mat_0016DD28* func_00167600(Mat_0016DD28* m);
extern "C" void func_001671A8(Mat_0016DD28* m, int a);
extern "C" void func_00168410(Mat_0016DD28* m, Node_0016DD28* n);
extern "C" void func_00168560(Mat_0016DD28* m, void* p);

extern "C" void func_0016DD28(Node_0016DD28* n, Mat_0016DD28* m, int flags)
{
    Mat_0016DD28* cur;
    unsigned int f = n->m1C;
    if (!(f & 1)) return;
    if (!(f & D_00394098)) return;
    if (f & 0x20) {
        cur = func_00167448(m);
        func_00167F00(cur);
        func_0016FFE8(n, cur, flags);
        if (D_0039427C) func_001617A0(0);
        return;
    }
    if (f & 4) {
        func_0016DED8(n, m, flags);
        return;
    }
    if (f & 8) {
        flags |= 0x10;
        cur = func_00167600(m);
        func_001671A8(cur, n->m24);
    } else {
        cur = m;
    }
    if (n->m1C & 0x800) {
        D_0038BCD4 = n;
        flags |= 0x20;
    }
    if (n->m1C & 0x10) {
        if (cur == m) cur = func_00167448(cur);
        func_00168410(cur, n);
        flags |= 8;
    }
    if (n->m2C && n->m2C != m->m54) {
        if (cur == m || (cur->m50 & 1) == 0) cur = func_00167600(m);
        func_00168560(cur, n->m2C);
    }
    for (Node_0016DD28* c = n->m20; c; c = c->m28) {
        func_0016DED8(c, cur, flags);
    }
}
