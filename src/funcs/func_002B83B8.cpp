struct Node_002B83B8 {
    int m0;
    int m4;
    Node_002B83B8* m8;
};

extern "C" void* func_0029C320();
extern "C" void func_0029A678(void* p);
extern "C" void func_0029A6B8(void* p);
extern "C" void* func_002B6CF8(Node_002B83B8* n);
extern "C" void func_001344A8(void* p);

struct Obj_002B83B8 {
    int m0;
    Node_002B83B8* m4;
    char pad[0x18 - 8];
    void* m18;
    void Stop(int keep);
};

extern "C" void func_002B8AA0(Obj_002B83B8* self, void* e, int keep);

void Obj_002B83B8::Stop(int keep)
{
    if (!keep) {
        func_0029A678(func_0029C320());
        func_0029A6B8(func_0029C320());
    }
    Node_002B83B8* n = m4;
    while (n) {
        Node_002B83B8* next = n->m8;
        func_002B8AA0(this, func_002B6CF8(n), keep);
        n = next;
    }
    if (!keep)
        m0 &= ~4;
    m0 &= ~8;
    if (!keep)
        func_001344A8(m18);
}
