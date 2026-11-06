/* sym: Detach__13Node_00170F58P13Node_00170F58 = 0x0016DB28 */
/* sym: DetachDeep__13Node_00170F58P13Node_00170F58 = 0x0016DB90 */
extern void* D_00388A70;
extern char D_003E0FE0[];
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00165058();

struct Node_00170F58 {
    char pad0[0x20];
    Node_00170F58* m20;
    int m24;
    Node_00170F58* m28;
    char pad2C[0x4C - 0x2C];
    Node_00170F58* m4C;
    bool Detach(Node_00170F58* parent);
    bool DetachDeep(Node_00170F58* parent);
};

extern "C" int func_00170518(Node_00170F58* n);
extern "C" int func_00170528(Node_00170F58* n);

void func_00170F58(Node_00170F58* n, int detach)
{
    func_00165058();
    if (detach) {
        if (!n->Detach((Node_00170F58*)D_003E0FE0))
            n->DetachDeep((Node_00170F58*)D_003E0FE0);
    }
    if (func_00170518(n)) {
        if (n->m20)
            func_0010A8D8(D_00388A70, n->m20);
    } else {
        if (func_00170528(n) && n->m4C)
            func_00170F58(n->m4C, 0);
        Node_00170F58* c = n->m20;
        while (c) {
            Node_00170F58* next = c->m28;
            func_00170F58(c, 0);
            c = next;
        }
    }
    if (n)
        func_0010A8D8(D_00388A70, n);
}
