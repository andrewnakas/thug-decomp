struct Node_002457B8 {
    char pad[8];
    int m_8;
};

struct Item_002457B8 {
    char pad[0x20];
    void* m_20;
    void* m_24;
    char pad28[0x60 - 0x28];
    int m_60;
    void Clear();
};

extern "C" Node_002457B8* func_001E6E90(void* params, Node_002457B8* prev);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

void Item_002457B8::Clear()
{
    Node_002457B8* p = func_001E6E90(m_24, 0);
    while (p) {
        Node_002457B8* next = func_001E6E90(m_24, p);
        p->m_8 = 0;
        p = next;
    }
    m_60 = 0;
    func_001E7200(m_20, 0xCF6CD3C1, 0);
}
