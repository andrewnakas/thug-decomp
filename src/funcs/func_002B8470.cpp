struct Node_002B8470 {
    int m0;
    int m4;
    Node_002B8470* m8;
};

struct List_002B8470 {
    int m0;
    Node_002B8470* m4;
};

extern "C" void* func_002B6CF8(Node_002B8470* n);
extern "C" void func_002B70A8(void* i, int v, int f);

extern "C" void func_002B8470(List_002B8470* l, int v)
{
    Node_002B8470* n = l->m4;
    while (n) {
        Node_002B8470* next = n->m8;
        func_002B70A8(func_002B6CF8(n), v, 0);
        n = next;
    }
}
