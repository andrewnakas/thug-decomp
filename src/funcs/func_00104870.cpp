/* sym: _vt$13Task_00104870 = 0x0035A938 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Node_00104870 {
public:
    int m0;
    int m4;
    int m8;
    Node_00104870* m_prev;
    Node_00104870* m_next;
    virtual ~Node_00104870();
};

class Task_00104870 {
public:
    int m0;
    int m4;
    Node_00104870* m_node;
    int mC;
    int m10;
    int m14;
    virtual void Func1() = 0;
    virtual void Func2() = 0;
    virtual ~Task_00104870() = 0;
    virtual void Func4();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_001048F0(Task_00104870* self);

Task_00104870::~Task_00104870()
{
    if (mC) {
        func_001048F0(this);
    }
    if (m_node) {
        delete m_node;
    }
}
