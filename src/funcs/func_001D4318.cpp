/* sym: _vt$12Obj_001D4318 = 0x00364230 */
/* sym: _$_13Base_001D4318 = 0x001D33D8 */
struct Data_001D4318 {
    int m0;
    int m4;
    int m8;
    virtual ~Data_001D4318();
};

struct Node_001D4318 {
    int m0;
    Data_001D4318* m_data;
    Node_001D4318* m_prev;
    Node_001D4318* m_next;
    int m10;
    virtual ~Node_001D4318();
    Node_001D4318* Next()
    {
        Node_001D4318* n = m_next;
        if (n->m_data == (Data_001D4318*)-1)
            return 0;
        return n;
    }
};

extern "C" void func_001DAE80(void* self);

struct Base_001D4318 {
    int m0;
    int m4;
    int m8;
    virtual ~Base_001D4318();
};

struct Obj_001D4318 : Base_001D4318 {
    Node_001D4318* m_list;
    virtual void Update();
    virtual ~Obj_001D4318();
};

Obj_001D4318::~Obj_001D4318()
{
    if (m_list) {
        Node_001D4318* n = m_list->Next();
        while (n) {
            Node_001D4318* next = n->Next();
            delete n->m_data;
            delete n;
            n = next;
        }
        delete m_list;
    }
    func_001DAE80(this);
}
