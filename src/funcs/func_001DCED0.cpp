struct Node_001DCED0 {
    char pad[0xC];
    int mC;
    Node_001DCED0* m10;
};
extern Node_001DCED0* D_0038E0AC;
extern "C" void func_001DCE40(void* self, Node_001DCED0* n, int v);

void func_001DCED0(void* self, int id)
{
    Node_001DCED0* n = D_0038E0AC;
    while (n) {
        Node_001DCED0* cur = n;
        n = n->m10;
        if (cur->mC == id)
            func_001DCE40(self, cur, 1);
    }
}
