extern char D_0035A938[];
extern char D_0035A960[];
extern "C" void* func_001046B0(int size);

struct Task_001047F8;

struct Node_001047F8 {
    int m0;
    Task_001047F8* m_owner;
    int m_data;
    Node_001047F8* m_prev;
    Node_001047F8* m_next;
    void* m_vtbl;

    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Node_001047F8(Task_001047F8* owner, int data)
    {
        m_data = data;
        m_owner = owner;
        m_vtbl = D_0035A960;
        m_prev = this;
        m_next = this;
    }
};

struct Task_001047F8 {
    int m0;
    int m4;
    Node_001047F8* m_node;
    int mC;
    int m10;
    int m14;
    void* m_vtbl;
    Task_001047F8(int data);
};

Task_001047F8::Task_001047F8(int data)
{
    m4 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m_vtbl = D_0035A938;
    m_node = new Node_001047F8(this, data);
}
