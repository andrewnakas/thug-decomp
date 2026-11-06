struct Node_00170E08 {
    char pad0[0x20];
    void* m20;
    int m24;
    Node_00170E08* m28;
    char pad2C[0x4C - 0x2C];
    Node_00170E08* m4C;
};

extern void* D_00388A70;
extern char D_003E0FE0[];

extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" Node_00170E08* func_0016DC80(void* mem, Node_00170E08* src);
extern "C" void func_0016DAF0(Node_00170E08* n, void* mat);
extern "C" void func_00170578(Node_00170E08* n, int a);
extern "C" int func_00170518(Node_00170E08* n);
extern "C" int func_00170528(Node_00170E08* n);
extern "C" int func_00161850(void* p);
extern "C" void func_00161A10(void* src, void* dst);
extern "C" void func_001706A8(Node_00170E08* n, Node_00170E08* c);

extern "C" Node_00170E08* func_00170E08(Node_00170E08* src, void* mat, int setMat)
{
    Node_00170E08* n = func_0016DC80(func_0010A638(D_00388A70, 0x50, 1, 0), src);
    n->m28 = 0;
    if (setMat) {
        if (mat) {
            func_0016DAF0(n, mat);
        } else {
            func_0016DAF0(n, D_003E0FE0);
        }
    }
    func_00170578(n, 1);
    if (func_00170518(src)) {
        n->m20 = func_0010A638(D_00388A70, func_00161850(src->m20), 1, 0);
        func_00161A10(src->m20, n->m20);
        return n;
    }
    if (func_00170528(src)) {
        if (src->m4C) n->m4C = func_00170E08(src->m4C, 0, 0);
    }
    n->m20 = 0;
    for (Node_00170E08* c = (Node_00170E08*)src->m20; c; c = c->m28) {
        func_001706A8(n, func_00170E08(c, 0, 0));
    }
    return n;
}
