struct Node_002B7740 {
    int m0;
    int m4;
    Node_002B7740* m8;
};

struct Elem_002B7740 {
    int m_id;
};

extern char D_00379FA8[];
extern "C" Elem_002B7740* func_002B6CF0(Node_002B7740* n);
extern "C" char* func_001E61F0(int id);
extern "C" void func_00103F28(const char* fmt, ...);

struct List_002B7740 {
    int m0;
    int m4;
    Node_002B7740* m8;
    Elem_002B7740* Find(int id, int quiet);
};

Elem_002B7740* List_002B7740::Find(int id, int quiet)
{
    for (Node_002B7740* n = m8; n; n = n->m8) {
        if (func_002B6CF0(n)->m_id == id)
            return func_002B6CF0(n);
    }
    if (!quiet)
        func_00103F28(D_00379FA8, func_001E61F0(id));
    return 0;
}
