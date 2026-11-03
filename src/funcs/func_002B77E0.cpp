struct Elem_002B77E0 {
    void* m0;
    char pad4[0x24];
    int m28;
    int m2C;
};

struct Hold_002B77E0 {
    char pad[0x14];
    Elem_002B77E0* m14;
};

struct Node_002B77E0 {
    int m0;
    unsigned int m4;
    char pad8[8];
    int m10;
    Elem_002B77E0* m14;
};

extern void* D_00388A70;
extern "C" Elem_002B77E0* func_002B6CF0(Node_002B77E0* n);
extern "C" Hold_002B77E0* func_002B6CF8(Node_002B77E0* n);
extern "C" int func_00133300(void* a, void* b, void* c, int d, int e);
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" Node_002B77E0* func_002B6E98(void* p);
extern "C" void func_002B6F30(Node_002B77E0* n, int v, int a);

struct List_002B77E0 {
    unsigned int m0;
    char pad4[8];
    int mC;
    char pad10[4];
    void* m14;
    void* m18;
    int m1C;
    char pad20[4];
    int m24;
    char pad28[0x9C - 0x28];
    int m9C;
    int mA0;
    Node_002B77E0* Add(Node_002B77E0* src, unsigned int flags);
};

Node_002B77E0* List_002B77E0::Add(Node_002B77E0* src, unsigned int flags)
{
    unsigned int f = flags & 0x124;
    Elem_002B77E0* e;
    if (src->m4 & 1)
        e = func_002B6CF0(src);
    else
        e = func_002B6CF8(src)->m14;
    int h;
    if (f & 4) {
        h = func_00133300(m14, e->m0, m18, 1, 0);
    } else {
        h = func_00133300(m14, e->m0, m18, 0, 1);
        if (!(f & 0x100)) {
            m9C += e->m28;
            mA0 += e->m2C;
        }
    }
    func_0010A950(D_00388A70, m24);
    Node_002B77E0* n = func_002B6E98(func_0010A638(D_00388A70, 0x40, 1, 0));
    func_0010A9B0(D_00388A70);
    n->m0 = h;
    n->m10 = m1C++;
    n->m14 = e;
    func_002B6F30(n, 0, 0);
    mC++;
    n->m4 |= f;
    m0 |= 4;
    return n;
}
