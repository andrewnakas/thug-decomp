struct Node_0029C158 {
    int m0;
    Node_0029C158* m4;
};

struct Obj_0029C158 {
    char pad[0x24];
    Node_0029C158* m24;
};

extern "C" void func_0029A030(Node_0029C158* n, int v);

extern "C" void func_0029C158(Obj_0029C158* o, int v)
{
    for (Node_0029C158* n = o->m24; n; n = n->m4)
        func_0029A030(n, v);
}
