struct Node_002CE080 {
    char pad0[0x18];
    Node_002CE080* m18;
};

extern "C" void func_002CCEF8(Node_002CE080* n, int a, int b, int c, int d);

struct Obj_002CE080 {
    char pad0[7];
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    char padB;
    Node_002CE080* mC;
    void Run(int c, int d);
};

void Obj_002CE080::Run(int c, int d)
{
    unsigned a = (unsigned)(m7 + m9) >> 1;
    unsigned b = (unsigned)(m8 + mA) >> 1;
    for (Node_002CE080* n = mC; n; n = n->m18)
        func_002CCEF8(n, a, b, c, d);
}
