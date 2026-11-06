struct Node_0026B9D8 {
    char pad[0x88];
    Node_0026B9D8* m88;
};

struct List_0026B9D8 {
    int m0;
    Node_0026B9D8* m4;
};

struct Game_0026B9D8 {
    char pad[0x2C];
    List_0026B9D8* m2C;
};

extern Game_0026B9D8* D_0038FC78;

void Walk_0026B9D8()
{
    for (Node_0026B9D8* n = D_0038FC78->m2C->m4; n; n = n->m88) {
    }
}
