struct Node_0026BA78 {
    char pad[0xC];
    int mC;
    char pad2[0x88 - 0x10];
    Node_0026BA78* m88;
};

struct List_0026BA78 {
    int m0;
    Node_0026BA78* m4;
};

struct Game_0026BA78 {
    char pad[0x2C];
    List_0026BA78* m2C;
};

extern Game_0026BA78* D_0038FC78;

Node_0026BA78* Find_0026BA78(int id)
{
    for (Node_0026BA78* n = D_0038FC78->m2C->m4; n; n = n->m88) {
        if (n->mC == id)
            return n;
    }
    return 0;
}
