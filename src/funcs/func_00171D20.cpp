extern int D_00393F50;

struct Node171D20 {
    char m_pad[0x20];
    Node171D20* m20;
    char m_pad24[0x28 - 0x24];
    Node171D20* m28;
    char m_pad2C[0x4C - 0x2C];
    Node171D20* m4C;
    void Walk(int* out, int reset);
};

extern "C" int func_00170518(Node171D20* n);
extern "C" int func_00170528(Node171D20* n);
extern "C" int func_00161860(Node171D20* g);
extern "C" void func_00162000(Node171D20* g, int* out);

void Node171D20::Walk(int* out, int reset)
{
    if (reset) {
        D_00393F50 = 0;
    }
    if (func_00170518(this)) {
        int n = func_00161860(m20);
        func_00162000(m20, out + D_00393F50);
        D_00393F50 += n;
    } else {
        if (func_00170528(this)) {
            if (m4C) {
                m4C->Walk(out, 0);
            }
        }
        for (Node171D20* c = m20; c; c = c->m28) {
            c->Walk(out, 0);
        }
    }
}
