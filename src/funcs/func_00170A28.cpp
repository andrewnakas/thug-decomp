struct Node_00170A28 {
    char pad0[0x1C];
    unsigned int m1C;
    Node_00170A28* m20;
    int m24;
    Node_00170A28* m28;
    char pad2C[0x4C - 0x2C];
    Node_00170A28* m4C;
};

extern "C" int func_00170518(Node_00170A28* n);
extern "C" int func_00170528(Node_00170A28* n);
extern "C" int func_00161908(void* pkt);

int func_00170A28(Node_00170A28* n)
{
    int r = 0;
    if (func_00170518(n)) {
        if (!(n->m1C & 0x600C0))
            r = func_00161908(n->m20);
        return r;
    }
    if (func_00170528(n) && n->m4C)
        r = func_00170A28(n->m4C);
    for (Node_00170A28* c = n->m20; c; c = c->m28)
        r += func_00170A28(c);
    return r;
}
