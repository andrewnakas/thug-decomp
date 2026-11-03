class Heap_0010AFE0 {
public:
    char pad[0x80];
    virtual void V1();
    virtual void V2();
    virtual ~Heap_0010AFE0();
};

struct Mem_0010AFE0 {
    int m0;
    Heap_0010AFE0* m_heaps[32];
    int m_numHeaps;
    void DeleteHeap(Heap_0010AFE0* heap);
};

void Mem_0010AFE0::DeleteHeap(Heap_0010AFE0* heap)
{
    for (int i = 0; i < m_numHeaps; i++) {
        if (m_heaps[i] == heap) {
            m_numHeaps--;
            m_heaps[i] = m_heaps[m_numHeaps];
            break;
        }
    }
    if (heap)
        delete heap;
}
