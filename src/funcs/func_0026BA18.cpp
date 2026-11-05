extern "C" void func_0026BDF0(void* p, bool on);

struct Node_0026BA18 {
    int m0;
    int m4;
    char pad[0x88 - 0x8];
    Node_0026BA18* m88;
};

struct List_0026BA18 {
    int m0;
    Node_0026BA18* m4;
};

struct Game_0026BA18 {
    char pad[0x2C];
    List_0026BA18* m2C;
};

extern Game_0026BA18* D_0038FC78;

void Set_0026BA18(int id, int on)
{
    List_0026BA18* l = D_0038FC78->m2C;
    if (!l)
        return;
    for (Node_0026BA18* n = l->m4; n; n = n->m88) {
        if (n->m4 == id) {
            func_0026BDF0(n, on);
            return;
        }
    }
}
