struct Node_002C7318 {
    char pad0[0x14];
    Node_002C7318* m14;
};

extern "C" void func_002CD490(Node_002C7318* n, int flags);

struct Obj_002C7318 {
    char pad0[0x68];
    Node_002C7318* m68;
    int m6C;
    void Clear();
};

void Obj_002C7318::Clear()
{
    Node_002C7318* n = m68;
    while (n) {
        Node_002C7318* next = n->m14;
        if (n)
            func_002CD490(n, 3);
        n = next;
    }
    m6C = 0;
}
