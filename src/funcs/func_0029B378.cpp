struct Node_0029B378 {
    int m0;
    Node_0029B378* m4;
    Node_0029B378* m8;
};

extern "C" void* func_0029C530(int size);
extern "C" Node_0029B378* func_00299540(void* p);

struct Obj_0029B378 {
    char pad0[0x24];
    Node_0029B378* m24;
    Node_0029B378* m28;
    Node_0029B378* Push();
};

Node_0029B378* Obj_0029B378::Push()
{
    Node_0029B378* n = func_00299540(func_0029C530(0x14));
    Node_0029B378* h = m24;
    n->m8 = 0;
    n->m4 = h;
    if (h)
        h->m8 = n;
    m24 = n;
    m28 = n;
    return n;
}
