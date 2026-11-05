struct Node_001F2EA0 {
    int m0;
    char m4[4];
};
struct Obj_001F2EA0 {
    char pad[0x18];
    void* m18;
    void Remove(Node_001F2EA0* n);
};
extern "C" void func_001F3450(void* list, void* link);
extern "C" void func_001F2E40(Obj_001F2EA0* self, Node_001F2EA0* n);
extern "C" void func_001F2C88(Node_001F2EA0* n, int flags);

void Obj_001F2EA0::Remove(Node_001F2EA0* n)
{
    func_001F3450(m18, n->m4);
    func_001F2E40(this, n);
    if (n)
        func_001F2C88(n, 3);
}
