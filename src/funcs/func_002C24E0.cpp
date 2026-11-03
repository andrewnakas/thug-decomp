extern void* D_00388A70;
extern "C" void* func_002BC5A0(void* n);
extern "C" int func_002B74E0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_002C48E0(unsigned int size);

struct Node_002C24E0 {
    char pad0[0x8];
    void* m8;
    Node_002C24E0* mC;
};

struct Obj_002C24E0 {
    void* m0;
    void Add(void* key, Node_002C24E0** head);
};

void Obj_002C24E0::Add(void* key, Node_002C24E0** head)
{
    for (Node_002C24E0* n = *head; n; n = n->mC) {
        if (func_002BC5A0(n) == key) return;
    }
    void* pool = D_00388A70;
    func_0010A950(pool, func_002B74E0(m0));
    Node_002C24E0* n = (Node_002C24E0*)func_002C48E0(0x10);
    func_0010A9B0(D_00388A70);
    n->m8 = key;
    n->mC = *head;
    *head = n;
}
