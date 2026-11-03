struct Heap_00171848 {
    char m0[0xD8];
    void* m_context;
};

struct V_00171848 {
    float x;
    float y;
    float z;
    float w;
};

struct Node_00171848 {
    float x;
    float y;
    float z;
    float m_radius;
    int m10[4];
    void* m_mesh;
    int m24;
    Node_00171848* m_next;
    int m2C[8];
    Node_00171848* m_child;
};

extern Heap_00171848* D_00388A70;
extern int D_00393F4C;
extern "C" int func_00170518(Node_00171848* n);
extern "C" int func_00170528(Node_00171848* n);
extern "C" int func_001708F8(Node_00171848* n);
extern "C" int func_00161860(void* mesh);
extern "C" int func_00161C98(void* mesh);
extern "C" void func_00161E70(void* mesh, int* verts, int a);
extern "C" void func_00171AB8(Node_00171848* n, V_00171848* pts, int count);
extern "C" void func_0010A950(Heap_00171848* heap, void* context);
extern "C" void* func_0010A638(Heap_00171848* heap, int size, int a, int b);
extern "C" void func_0010A8D8(Heap_00171848* heap, void* p);
extern "C" void func_0010A9B0(Heap_00171848* heap);

extern "C" void func_00171848(Node_00171848* n, V_00171848* pts, int reset)
{
    if (reset) {
        D_00393F4C = 0;
    }
    if (func_00170518(n)) {
        int count = func_00161860(n->m_mesh);
        func_00171AB8(n, &pts[D_00393F4C], count);
        func_0010A950(D_00388A70, D_00388A70->m_context);
        int* verts = (int*)func_0010A638(D_00388A70, count * 16, 1, 0);
        int base[3];
        if (func_00161C98(n->m_mesh) < 0x20) {
            base[0] = (int)(n->x * 16.0f);
            base[1] = (int)(n->y * 16.0f);
            base[2] = (int)(n->z * 16.0f);
        }
        for (int i = 0; i < count; i++) {
            int* p = &verts[i * 4];
            if (func_00161C98(n->m_mesh) == 0x20) {
                V_00171848* v = (V_00171848*)(D_00393F4C * sizeof(V_00171848) + (unsigned int)pts);
                p[0] = (int)(v->x * 16.0f);
                p[1] = (int)(v->y * 16.0f);
                p[2] = (int)(v->z * 16.0f);
            } else {
                V_00171848* v = (V_00171848*)(D_00393F4C * sizeof(V_00171848) + (unsigned int)pts);
                p[0] = (int)(v->x * 16.0f) - base[0];
                p[1] = (int)(v->y * 16.0f) - base[1];
                p[2] = (int)(v->z * 16.0f) - base[2];
            }
            D_00393F4C++;
        }
        func_00161E70(n->m_mesh, verts, 1);
        if (verts) {
            func_0010A8D8(D_00388A70, verts);
        }
        func_0010A9B0(D_00388A70);
    } else {
        if (func_00170528(n)) {
            if (n->m_child) {
                func_00171848(n->m_child, pts, 0);
            }
        }
        for (Node_00171848* c = (Node_00171848*)n->m_mesh; c; c = c->m_next) {
            func_00171848(c, pts, 0);
        }
        func_00171AB8(n, pts, func_001708F8(n));
    }
}
