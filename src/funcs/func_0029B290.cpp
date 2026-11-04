struct Node_0029B290 {
    int m0;
    Node_0029B290* m4;
};

struct Obj_0029B290 {
    char pad[0x24];
    Node_0029B290* m24;
    int m28;
    int m2C;
};

extern "C" void func_00299588(Node_0029B290* n, int f);
extern "C" void func_0029B6E0(Obj_0029B290* o);

extern "C" void func_0029B290(Obj_0029B290* o)
{
    Node_0029B290* n = o->m24;
    while (n) {
        Node_0029B290* next = n->m4;
        if (n)
            func_00299588(n, 3);
        n = next;
    }
    o->m24 = 0;
    o->m28 = 0;
    o->m2C = 0;
    func_0029B6E0(o);
}
