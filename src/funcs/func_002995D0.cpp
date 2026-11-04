struct Node_002995D0 {
    char pad0[0x2C];
    Node_002995D0* m2C;
};

extern "C" void func_002984B8(Node_002995D0* n, int flags);

struct Obj_002995D0 {
    char pad0[0xC];
    Node_002995D0* mC;
    void Clear();
};

void Obj_002995D0::Clear()
{
    Node_002995D0* n = mC;
    while (n) {
        Node_002995D0* next = n->m2C;
        if (n)
            func_002984B8(n, 3);
        n = next;
    }
    mC = 0;
}
