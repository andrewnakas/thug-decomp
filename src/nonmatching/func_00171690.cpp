/* fuzzy: 73.4 */
struct Heap_00171690 {
    char pad[0xD8];
    void* m_D8;
};

/* A vertex slot: filled with fixed-point integers (1/16 units) by func_00161D50, converted to floats in place. */
union Vec_00171690 {
    int i[4];
    float f[4];
};

struct Node_00171690 {
    float m_pos[3];
    char padC[0x20 - 0xC];
    Node_00171690* m_child;
    char pad24[4];
    Node_00171690* m_sibling;
    char pad2C[0x4C - 0x2C];
    Node_00171690* m_4C;
};

extern int D_00393F48;
extern Heap_00171690* D_00388A70;
extern "C" int func_00170518(Node_00171690* n);
extern "C" int func_00170528(Node_00171690* n);
extern "C" int func_00161860(Node_00171690* mesh);
extern "C" void func_00161D50(Node_00171690* mesh, Vec_00171690* out);
extern "C" void func_0010A950(Heap_00171690* heap, void* sub);
extern "C" void func_0010A9B0(Heap_00171690* heap);

void func_00171690(Node_00171690* node, Vec_00171690* out, int reset)
{
    if (reset)
        D_00393F48 = 0;
    if (func_00170518(node)) {
        int count = func_00161860(node->m_child);
        func_0010A950(D_00388A70, D_00388A70->m_D8);
        Vec_00171690* src = &out[D_00393F48];
        func_00161D50(node->m_child, src);
        int ofs[3];
        ofs[2] = (int)(node->m_pos[2] * 16.0f);
        ofs[0] = (int)(node->m_pos[0] * 16.0f);
        ofs[1] = (int)(node->m_pos[1] * 16.0f);
        for (int i = 0; i < count; i++) {
            Vec_00171690* d = &out[D_00393F48];
            d->f[0] = (float)(src->i[0] + ofs[0]) * 0.0625f;
            d->f[1] = (float)(src->i[1] + ofs[1]) * 0.0625f;
            d->f[3] = 1.0f;
            d->f[2] = (float)(src->i[2] + ofs[2]) * 0.0625f;
            src++;
            D_00393F48 = D_00393F48 + 1;
        }
        func_0010A9B0(D_00388A70);
    } else {
        if (func_00170528(node) && node->m_4C)
            func_00171690(node->m_4C, out, 0);
        for (Node_00171690* c = node->m_child; c; c = c->m_sibling)
            func_00171690(c, out, 0);
    }
}
