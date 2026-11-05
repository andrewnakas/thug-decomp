struct Vec_0026A0D0 {
    float x, y, z, w;
};

struct Node_0026A0D0 {
    char pad0[0x50];
    Node_0026A0D0* m50;
    Node_0026A0D0* m54;
    int m58;
    char pad5C[0x4];
};

struct Graph_0026A0D0 {
    char pad0[0x50];
    Node_0026A0D0* m_nodes;
    char pad54[0x8];
    int m_count;
};

extern "C" bool func_0026A058(Graph_0026A0D0* g, Node_0026A0D0* n, Node_0026A0D0* ref);
extern "C" bool func_001CB7B8(Node_0026A0D0* n, int a);
extern "C" void func_0026B1B0(Vec_0026A0D0* out, Graph_0026A0D0* g, Node_0026A0D0* n);
extern "C" bool func_0026A968(Vec_0026A0D0* a, Vec_0026A0D0* b);

int func_0026A0D0(Graph_0026A0D0* g, Node_0026A0D0* ref, int mask, Node_0026A0D0** out)
{
    for (int i = 0; i < g->m_count; i++) {
        Node_0026A0D0* n = &g->m_nodes[i];
        if (!func_0026A058(g, n, ref)) continue;
        if (!n->m50 && !n->m54) continue;
        if (n == ref) continue;
        Vec_0026A0D0 a;
        Vec_0026A0D0 b;
        if (n->m50 && func_001CB7B8(n, 2) && !(n->m58 & mask)) {
            func_0026B1B0(&a, g, n);
            func_0026B1B0(&b, g, n->m50);
            if (func_0026A968(&a, &b)) {
                *out = n;
                return 1;
            }
        }
        if (n->m54 && func_001CB7B8(n->m54, 2) && !(n->m54->m58 & mask)) {
            func_0026B1B0(&a, g, n->m54);
            func_0026B1B0(&b, g, n);
            if (func_0026A968(&a, &b)) {
                *out = n->m54;
                return 1;
            }
        }
    }
    return 0;
}
