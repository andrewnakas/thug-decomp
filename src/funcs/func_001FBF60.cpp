struct Node_001FBF60 {
    void* m_data;
    unsigned int m_flag;
    int m_pri;
    Node_001FBF60* m_next;
    Node_001FBF60* m_prev;
    Node_001FBF60* GetItem() { return m_flag == 0xFFFFFFFF ? 0 : this; }
    void InsertBefore(Node_001FBF60* node)
    {
        node->m_prev = m_prev;
        node->m_next = this;
        m_prev->m_next = node;
        m_prev = node;
    }
};

struct Bucket_001FBF60 {
    Node_001FBF60 m_head;
    int m14;
    void Add(Node_001FBF60* node)
    {
        int pri = node->m_pri;
        for (Node_001FBF60* item = m_head.m_next->GetItem(); item; item = item->m_next->GetItem()) {
            if (pri >= item->m_pri) {
                item->InsertBefore(node);
                return;
            }
        }
        m_head.InsertBefore(node);
    }
};

struct Heap_001FBF60 {
    char m_pad[0xF4];
    void* m_heap;
};

extern Heap_001FBF60* D_00388A70;

extern "C" void func_0010A950(Heap_001FBF60* mem, void* heap);
extern "C" void func_0010A9B0(Heap_001FBF60* mem);
extern "C" void* func_001046B0(int size);
extern "C" Node_001FBF60* func_001FBF30(void* mem, int a, int b, int c, int d);

Node_001FBF60* func_001FBF60(Bucket_001FBF60* buckets, unsigned char index, int a, int b, int c, int d)
{
    func_0010A950(D_00388A70, D_00388A70->m_heap);
    Node_001FBF60* node = func_001FBF30(func_001046B0(0x24), a, b, c, d);
    buckets[index].Add(node);
    func_0010A9B0(D_00388A70);
    return node;
}
