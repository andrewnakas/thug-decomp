struct Obj_0017B560 {
    char pad0[0x19C];
    Obj_0017B560* m_next;
};

struct Node_0017B560 {
    char pad0[0x4C];
    Node_0017B560* m_next;
};

extern int D_0038C010;
extern int D_0038C00C;
extern Obj_0017B560* D_00393F60;
extern Node_0017B560* D_0038C0F8;
extern "C" void func_00173110(Obj_0017B560* o);
extern "C" void func_0017ED30(Node_0017B560* n);

extern "C" void func_0017B560()
{
    if (D_0038C00C) {
        for (Obj_0017B560* o = D_00393F60; o; o = o->m_next) {
            func_00173110(o);
        }
        for (Node_0017B560* n = D_0038C0F8; n; n = n->m_next) {
            func_0017ED30(n);
        }
        D_0038C00C = 0;
    }
}
