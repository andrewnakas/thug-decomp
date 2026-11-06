struct Stats_00170838 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct Node_00170838 {
    char pad0[0x20];
    Node_00170838* m20;
    int m24;
    Node_00170838* m28;
};

extern "C" int func_00170528(Node_00170838* n);
extern "C" int func_00170518(Node_00170838* n);
extern "C" int func_00161860(void* pkt);
extern "C" int func_00161908(void* pkt);

void func_00170838(Node_00170838* n, Stats_00170838* s)
{
    s->m4++;
    if (func_00170528(n))
        s->mC++;
    if (func_00170518(n)) {
        s->m8++;
        s->m10 += func_00161860(n->m20);
        s->m14 += func_00161908(n->m20);
        return;
    }
    for (Node_00170838* c = n->m20; c; c = c->m28)
        func_00170838(c, s);
}
