struct Node_002CDFD8 {
    char pad0[0x18];
    Node_002CDFD8* m18;
};

extern "C" int func_002CCE40(Node_002CDFD8* n, int a, int b, int c);

struct Obj_002CDFD8 {
    char pad0[7];
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    char padB;
    Node_002CDFD8* mC;
    int Run(int c);
};

int Obj_002CDFD8::Run(int c)
{
    int best = -1000;
    unsigned a = (unsigned)(m7 + m9) >> 1;
    unsigned b = (unsigned)(m8 + mA) >> 1;
    for (Node_002CDFD8* n = mC; n; n = n->m18) {
        int v = func_002CCE40(n, a, b, c);
        if (v > best)
            best = v;
    }
    if (best == -1000)
        return 0;
    return best;
}
