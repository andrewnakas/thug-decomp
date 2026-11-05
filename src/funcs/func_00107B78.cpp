/* sym: _vt$12Obj_00107B78 = 0x0035AEF0 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0010BEB8(void* p);
extern void* D_00388A70;

class Node_00107B78 {
public:
    int m0;
    int m4;
    int m8;
    Node_00107B78* m_prev;
    Node_00107B78* m_next;
    virtual ~Node_00107B78();
};

class Obj_00107B78 {
public:
    int m0;
    Node_00107B78* m_node;
    char pad[0xD8 - 8];
    void* mD8;
    char padDC[0xEC - 0xDC];
    virtual ~Obj_00107B78() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00107B78::~Obj_00107B78()
{
    func_0010BEB8(mD8);
    if (m_node) {
        delete m_node;
    }
}
