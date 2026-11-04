extern int D_00393F54;

struct Node171DE8 {
    char m_pad[0x20];
    Node171DE8* m20;
    char m_pad24[0x28 - 0x24];
    Node171DE8* m28;
    char m_pad2C[0x4C - 0x2C];
    Node171DE8* m4C;
    void Walk(int* out, int reset);
};

extern "C" int func_00170518(Node171DE8* n);
extern "C" int func_00170528(Node171DE8* n);
extern "C" int func_00161860(Node171DE8* g);
extern "C" void func_00162020(Node171DE8* g, int* out);

void Node171DE8::Walk(int* out, int reset)
{
    if (reset) {
        D_00393F54 = 0;
    }
    if (func_00170518(this)) {
        int n = func_00161860(m20);
        func_00162020(m20, out + D_00393F54);
        D_00393F54 += n;
    } else {
        if (func_00170528(this)) {
            if (m4C) {
                m4C->Walk(out, 0);
            }
        }
        for (Node171DE8* c = m20; c; c = c->m28) {
            c->Walk(out, 0);
        }
    }
}
