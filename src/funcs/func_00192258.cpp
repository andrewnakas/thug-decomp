extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);

struct V_00192258 {
    int m0;
    float x;
    float y;
    float z;
};
extern "C" V_00192258* func_001E9328(void* arr, unsigned int i);

struct A_00192258 {
    char pad[0xC];
    unsigned int m_size;
};

struct N_00192258 {
    float x;
    float y;
    float z;
    int mC;
    char pad10[0x10];
    char m20;
    char pad21[0xF];
    N_00192258() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct C_00192258 {
    char pad[0x50];
    N_00192258* m_nodes;
    unsigned short m_count;
    void SetNodes(A_00192258* arr);
};

void C_00192258::SetNodes(A_00192258* arr)
{
    unsigned int n = arr->m_size;
    m_count = n;
    delete[] m_nodes;
    m_nodes = new N_00192258[m_count];
    for (unsigned int i = 0; i < m_count; i++) {
        V_00192258* v = func_001E9328(arr, i);
        m_nodes[i].x = v->x;
        m_nodes[i].y = v->y;
        m_nodes[i].z = v->z;
        m_nodes[i].mC = 0;
        m_nodes[i].m20 = 0;
    }
}
