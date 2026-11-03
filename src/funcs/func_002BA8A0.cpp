extern char D_0037A3B0[];
extern "C" int func_001F0D78(char* s);

struct Node_002BA8A0 {
    int m0;
    unsigned int m4;
};

extern "C" void* func_002B7740(void* self, int id, int a);
extern "C" Node_002BA8A0* func_002B77E0(void* self, void* p, int a);
extern "C" void func_002B6EE8(Node_002BA8A0* n, int v, int a);
extern "C" void func_002B6F30(Node_002BA8A0* n, int v, int a);
extern "C" void func_002B7940(void* self, Node_002BA8A0* n);

struct Obj_002BA8A0 {
    Node_002BA8A0* Create(int a, int b);
};

Node_002BA8A0* Obj_002BA8A0::Create(int a, int b)
{
    Node_002BA8A0* n = func_002B77E0(this, func_002B7740(this, func_001F0D78(D_0037A3B0), 1), 0);
    func_002B6EE8(n, a, 1);
    func_002B6F30(n, b, 1);
    n->m4 |= 0x40;
    func_002B7940(this, n);
    return n;
}
