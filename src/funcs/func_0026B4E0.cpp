extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Node_0026B4E0 {
    char pad[0x20];
    Node_0026B4E0* m20;
};

struct Pool_0026B4E0 {
    int m0;
    Node_0026B4E0* m4;
    int m8;
    char pad[0x50 - 0xC];
    int m50;
    void Clear();
};

void Pool_0026B4E0::Clear()
{
    while (m4) {
        Node_0026B4E0* n = m4;
        Node_0026B4E0* next = n->m20;
        func_0010A8D8(D_00388A70, n);
        m4 = next;
    }
    m8 = 0;
    m50 = 0;
}
