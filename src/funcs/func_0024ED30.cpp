struct Array_0024ED30 {
    int pad[3];
    unsigned int m_size;
};

extern char D_00374990[];
extern "C" void* func_001046B0(unsigned int size);

struct Node_0024ED30 {
    int m0;
    void* m_data;
    int m_priority;
    Node_0024ED30* m_next;
    Node_0024ED30* m_prev;
    void* m_vtable;

    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Node_0024ED30(void* data)
    {
        m_next = this;
        m_prev = this;
        m_data = data;
        m_vtable = D_00374990;
        m_priority = 0;
    }
    void InsertBefore(Node_0024ED30* node)
    {
        m_prev = node->m_prev;
        m_next = node;
        node->m_prev->m_next = this;
        node->m_prev = this;
    }
};

struct Heaps_0024ED30 {
    char pad[0x3EC];
    void* m3EC;
};

struct Mgr_0024ED30 {
    int m0;
    char m4[8];
    Node_0024ED30 m_list;
};

extern Heaps_0024ED30* D_00388A70;
extern "C" void func_0024EC78(Mgr_0024ED30* self);
extern "C" bool func_001E8248(void* self, unsigned int name, Array_0024ED30** out, int assert_);
extern "C" void func_0010A950(void* heaps, void* heap);
extern "C" void func_0010A9B0(void* heaps);
extern "C" void* func_001E9378(void* self, int index);
extern "C" void* func_002507A0(void* self);
void func_0024ED30(Mgr_0024ED30* self)
{
    Array_0024ED30* arr;

    func_0024EC78(self);
    if (!func_001E8248(self->m4, 0x94A24C5E, &arr, 0))
        return;
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    unsigned int i = 0;
    if (arr->m_size) {
        do {
            void* item = func_002507A0(func_001E9378(arr, i));
            i++;
            Node_0024ED30* n = new Node_0024ED30(item);
            n->InsertBefore(&self->m_list);
        } while (i < arr->m_size);
    }
    func_0010A9B0(D_00388A70);
}
