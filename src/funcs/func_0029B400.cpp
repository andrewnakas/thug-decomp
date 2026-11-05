struct Obj2_0029B400 {
    char pad[0x2C];
    void* m2C;
};

struct Node_0029B400 {
    int m0;
    Node_0029B400* next;
    char pad8[4];
    Obj2_0029B400* mC;
};

struct Mgr_0029B400;
extern "C" void func_0029B2F8(Mgr_0029B400* self, Node_0029B400* n);

struct Mgr_0029B400 {
    char pad[0x24];
    Node_0029B400* m24;
    void Purge();
};

void Mgr_0029B400::Purge()
{
    Node_0029B400* n = m24;
    while (n) {
        Node_0029B400* next = n->next;
        if (!n->mC || !n->mC->m2C)
            func_0029B2F8(this, n);
        n = next;
    }
}
