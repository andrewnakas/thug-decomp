struct Node_002C00F0 {
    int m0;
    int m4;
    int m8;
    Node_002C00F0* mC;
};

struct Obj_002C00F0;
extern "C" void func_002C1E58(Obj_002C00F0* o);
extern "C" void* func_002BC5A0(Node_002C00F0* n);
extern "C" void* func_002BAB80(void* p);
extern "C" int func_002BF260(Obj_002C00F0* o, void* p, int a, int b, int c);

struct Obj_002C00F0 {
    int m0;
    int m4;
    int m8;
    Node_002C00F0* mC;
    void Rebuild();
};

void Obj_002C00F0::Rebuild()
{
    func_002C1E58(this);
    for (Node_002C00F0* n = mC; n; n = n->mC)
        n->m8 = func_002BF260(this, func_002BAB80(func_002BC5A0(n)), 0, -n->m4, 0);
}
