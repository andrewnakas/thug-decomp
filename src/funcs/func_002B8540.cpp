struct Node_002B8540 {
    int m0;
    int m4;
    Node_002B8540* m8;
};

struct Info_002B8540 {
    char pad[0x14];
    int m14;
};

extern void* D_0039274C;
extern "C" Info_002B8540* func_002B6CF8(Node_002B8540* n);
extern "C" int func_002B6E90(int id);
extern "C" void* func_002C3270(void* p, int id);
extern "C" void func_002B7150(Info_002B8540* i, int v);

struct Obj_002B8540 {
    int m0;
    Node_002B8540* m4;
    void Apply(int v);
};

void Obj_002B8540::Apply(int v)
{
    Node_002B8540* n = m4;
    while (n) {
        Node_002B8540* nx = n->m8;
        if (func_002C3270(D_0039274C, func_002B6E90(func_002B6CF8(n)->m14)))
            func_002B7150(func_002B6CF8(n), v);
        n = nx;
    }
}
