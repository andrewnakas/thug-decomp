struct Node170990 {
    char m_pad[0x20];
    Node170990* m20;
    char m_pad24[0x28 - 0x24];
    Node170990* m28;
    char m_pad2C[0x4C - 0x2C];
    Node170990* m4C;
    int Count();
};

extern "C" int func_00170518(Node170990* n);
extern "C" int func_00170528(Node170990* n);
extern "C" int func_00161908(Node170990* g);

int Node170990::Count()
{
    int n = 0;
    if (func_00170518(this)) {
        n = func_00161908(m20);
    } else {
        if (func_00170528(this)) {
            if (m4C) {
                n = m4C->Count();
            }
        }
        for (Node170990* c = m20; c; c = c->m28) {
            n += c->Count();
        }
    }
    return n;
}
