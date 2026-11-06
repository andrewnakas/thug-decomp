extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Node_0026B770 {
    char pad[0x88];
    Node_0026B770* m88;
};

struct List_0026B770 {
    int m0;
    Node_0026B770* m4;
};

struct Game_0026B770 {
    char pad[0x2C];
    List_0026B770* m2C;
};

extern Game_0026B770* D_0038FC78;

void Free_0026B770()
{
    Game_0026B770* g = D_0038FC78;
    if (!g->m2C)
        return;
    Node_0026B770* n = g->m2C->m4;
    while (n) {
        Node_0026B770* next = n->m88;
        func_0010A8D8(D_00388A70, n);
        n = next;
    }
    func_0010A8D8(D_00388A70, g->m2C);
    g->m2C = 0;
}
