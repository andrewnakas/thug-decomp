struct Node_0029A218 {
    int m0;
    Node_0029A218* m4;
    Node_0029A218* m8;
};

extern "C" short func_00299898(Node_0029A218* n);
extern "C" char* func_00299EC0(Node_0029A218* n, char* p);

struct Obj_0029A218;
extern "C" void func_0029A1E8(Obj_0029A218* o);
extern "C" short func_0029B468(Obj_0029A218* o);
struct Obj_0029A218 {
    char pad[0x24];
    Node_0029A218* m24;
    char pad2[0x38 - 0x28];
    short m38;
    short m3A[(0x1CA - 0x3A) / 2];
    char m1CA[1];
    void Build();
};

void Obj_0029A218::Build()
{
    short* s = m3A;
    char* p = m1CA;
    func_0029A1E8(this);
    m38 = func_0029B468(this);
    Node_0029A218* n = m24;
    while (n && n->m4)
        n = n->m4;
    for (; n; n = n->m8) {
        *s++ = func_00299898(n);
        p = func_00299EC0(n, p);
    }
}
