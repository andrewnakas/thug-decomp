/* fuzzy: 69.3 */
struct Heap_00171690 {
    char pad[0xD8];
    void* m_D8;
};

/* A vertex slot: filled with fixed-point integers by func_00161D50, converted to floats in place. */
struct IVec_00171690 {
    int x, y, z, w;
};

/* A vertex slot: filled with fixed-point integers (1/16 units) by func_00161D50, converted to floats in place. */
struct Vec_00171690 {
    float x, y, z, w;
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
        int* src = (int*)&out[D_00393F48];
        func_00161D50(node->m_child, (Vec_00171690*)src);
        IVec_00171690 ofs;
        ofs.z = (int)(node->m_pos[2] * 16.0f);
        ofs.x = (int)(node->m_pos[0] * 16.0f);
        ofs.y = (int)(node->m_pos[1] * 16.0f);
        for (int i = count; i > 0; i--) {
            float* d = (float*)&out[D_00393F48];
            d[0] = (float)(src[0] + ofs.x) * 0.0625f;
            d[1] = (float)(src[1] + ofs.y) * 0.0625f;
            d[3] = 1.0f;
            d[2] = (float)(src[2] + ofs.z) * 0.0625f;
            src += 4;
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
