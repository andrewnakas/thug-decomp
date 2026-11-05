struct Node_002BC698 {
    int m0;
    int m4;
    int m8;
    Node_002BC698* mC;
};

extern char D_0037A450[];
extern char D_0037A468[];
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void* func_002BC5A0(Node_002BC698* n);
extern "C" void func_002BAA80(void* p);

struct List_002BC698 {
    Node_002BC698* m0;
    void Dump();
};

void List_002BC698::Dump()
{
    func_00103F28(D_0037A450);
    for (Node_002BC698* n = m0; n; n = n->mC) {
        func_00103F28(D_0037A468, func_002BC5A0(n));
        func_002BAA80(func_002BC5A0(n));
    }
}
