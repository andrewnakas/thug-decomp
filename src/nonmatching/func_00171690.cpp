/* fuzzy: 51.4 */
struct Heap_00171690 {
    char pad[0xD8];
    void* m_D8;
};

struct IVec_00171690 {
    int x, y, z, w;
};

struct FVec_00171690 {
    float x, y, z, w;
};

/* A vertex slot: filled with fixed-point integers by func_00161D50, converted to floats in place. */
union Vec_00171690 {
    IVec_00171690 i;
    FVec_00171690 f;
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

/* Collects the vertices of a node tree into out[], advancing the global cursor D_00393F48. Mesh vertices come
   back as integers in 1/16 units; the node position is added and the result scaled back to floats. */
void func_00171690(Node_00171690* node, Vec_00171690* out, int reset)
{
    if (reset)
        D_00393F48 = 0;
    if (func_00170518(node)) {
        int count = func_00161860(node->m_child);
        func_0010A950(D_00388A70, D_00388A70->m_D8);
        Vec_00171690* src = &out[D_00393F48];
        func_00161D50(node->m_child, src);
        IVec_00171690 ofs;
        ofs.z = (int)(node->m_pos[2] * 16.0f);
        ofs.x = (int)(node->m_pos[0] * 16.0f);
        ofs.y = (int)(node->m_pos[1] * 16.0f);
        for (int i = count; i > 0; i--) {
            Vec_00171690* d = &out[D_00393F48];
            d->f.x = (float)(src->i.x + ofs.x) * 0.0625f;
            d->f.y = (float)(src->i.y + ofs.y) * 0.0625f;
            d->f.w = 1.0f;
            d->f.z = (float)(src->i.z + ofs.z) * 0.0625f;
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
