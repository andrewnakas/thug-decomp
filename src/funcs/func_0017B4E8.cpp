struct Obj_0017B4E8 {
    char pad0[0x19C];
    Obj_0017B4E8* m_next;
};

struct Node_0017B4E8 {
    char pad0[0x4C];
    Node_0017B4E8* m_next;
};

extern int D_0038C010;
extern int D_0038C00C;
extern Obj_0017B4E8* D_00393F60;
extern Node_0017B4E8* D_0038C0F8;
extern "C" void func_0017B4C0();
extern "C" void func_001730A8(Obj_0017B4E8* o);
extern "C" void func_0017ECB8(Node_0017B4E8* n);

extern "C" void func_0017B4E8()
{
    if (D_0038C010) {
        func_0017B4C0();
        for (Obj_0017B4E8* o = D_00393F60; o; o = o->m_next) {
            func_001730A8(o);
        }
        for (Node_0017B4E8* n = D_0038C0F8; n; n = n->m_next) {
            func_0017ECB8(n);
        }
        D_0038C010 = 0;
        D_0038C00C = 1;
    }
}
