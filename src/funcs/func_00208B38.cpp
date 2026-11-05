struct Node_00208B38 {
    int m0;
    int m_data;
    int m8;
    Node_00208B38* m_next;
    Node_00208B38* m_prev;
    virtual ~Node_00208B38();
    Node_00208B38* Valid() { if (m_data == -1) return 0; return this; }
};

extern "C" void func_00207EF8(void* c, void* b, int data);
extern "C" void func_00207E60(void* c, void* b);

extern "C" int func_00208B38(void* a, void* b, void* c, Node_00208B38* list, int n)
{
    if (n > 0) {
        Node_00208B38* node = list->m_next->Valid();
        func_00207EF8(c, b, node->m_data);
        delete node;
    } else {
        func_00207E60(c, b);
    }
    return n - 1;
}
