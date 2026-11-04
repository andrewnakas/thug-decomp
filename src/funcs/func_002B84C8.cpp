struct Node_002B84C8 {
    int m0;
    int m4;
    Node_002B84C8* m8;
};

struct Info_002B84C8 {
    int m0;
    unsigned int m4;
};

struct List_002B84C8 {
    int m0;
    Node_002B84C8* m4;
};

extern "C" Info_002B84C8* func_002B6CF8(Node_002B84C8* n);
extern "C" void func_002B7188(Info_002B84C8* i, int v);

extern "C" void func_002B84C8(List_002B84C8* l, int v)
{
    Node_002B84C8* n = l->m4;
    while (n) {
        Node_002B84C8* next = n->m8;
        if (func_002B6CF8(n)->m4 & 0x40)
            func_002B7188(func_002B6CF8(n), v);
        n = next;
    }
}
