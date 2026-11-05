extern char D_00363ED8[];
struct Node_001DAEF0 {
    int m0;
    void* m4;
    int m8;
    Node_001DAEF0* mC;
    Node_001DAEF0* m10;
    void* m14;
};
extern Node_001DAEF0 D_003E82E0;
extern "C" void* func_001046B0(int size);

void func_001DAEF0(void* p)
{
    Node_001DAEF0* n = (Node_001DAEF0*)func_001046B0(0x18);
    n->m4 = p;
    n->mC = n;
    n->m10 = n;
    n->m14 = D_00363ED8;
    n->m8 = 0;
    Node_001DAEF0* h = &D_003E82E0;
    Node_001DAEF0* prev = h->m10;
    n->mC = h;
    n->m10 = prev;
    h->m10->mC = n;
    h->m10 = n;

}
