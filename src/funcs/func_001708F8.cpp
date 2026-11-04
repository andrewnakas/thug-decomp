struct Node1708F8 {
    char m_pad[0x20];
    Node1708F8* m20;
    char m_pad24[0x28 - 0x24];
    Node1708F8* m28;
    char m_pad2C[0x4C - 0x2C];
    Node1708F8* m4C;
    int Count();
};

extern "C" int func_00170518(Node1708F8* n);
extern "C" int func_00170528(Node1708F8* n);
extern "C" int func_00161860(Node1708F8* g);

int Node1708F8::Count()
{
    int n = 0;
    if (func_00170518(this)) {
        n = func_00161860(m20);
    } else {
        if (func_00170528(this)) {
            if (m4C) {
                n = m4C->Count();
            }
        }
        for (Node1708F8* c = m20; c; c = c->m28) {
            n += c->Count();
        }
    }
    return n;
}
