typedef int qword_001D6960 __attribute__((mode(TI)));

struct Vec_001D6960 {
    qword_001D6960 q;
};

extern char D_00363EF0[];
extern void* D_00388A70;

struct Geom_001D6960 {
    char pad0[4];
    unsigned short m_flags;
    char pad6[2];
    void* m_data;
    void* m_vtbl;
    char pad10[0xA0];
    float m_radius;
    int m_B4;
    char padB8[8];
    Vec_001D6960 m_min;
    Vec_001D6960 m_max;
};

extern "C" Geom_001D6960* func_0010A638(void* heap, int size, int a, int b);
extern "C" Geom_001D6960* func_001D7248(Geom_001D6960* self, Geom_001D6960* src);
extern "C" void* func_001D8170(void* data, int a, int b);

Geom_001D6960* func_001D6960(Geom_001D6960* src, int a)
{
    Geom_001D6960* g = func_0010A638(D_00388A70, 0xE0, 1, 0);
    func_001D7248(g, src);
    g->m_vtbl = D_00363EF0;
    g->m_radius = src->m_radius;
    g->m_B4 = src->m_B4;
    g->m_min = src->m_min;
    g->m_max = src->m_max;
    g->m_flags |= 0x8000;
    g->m_data = func_001D8170(src->m_data, a, 0);
    return g;
}
