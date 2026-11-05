/* sym: _vt$12Obj_0010C488 = 0x0035B558 */
/* sym: _vt$13Node_0010C488 = 0x0035B5C8 */
/* sym: _$_12Sub_0010C488 = 0x0010C2B0 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Node_0010C488 {
public:
    int m0;
    int m4;
    int m8;
    Node_0010C488* m_prev;
    Node_0010C488* m_next;
    virtual void Run();
    virtual ~Node_0010C488()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

struct Sub_0010C488 {
    char pad[0x20];
    ~Sub_0010C488();
};

class Obj_0010C488;
extern "C" void func_0010C078(void* owner, Obj_0010C488* obj);

class Obj_0010C488 {
public:
    char pad[0x34];
    void* m34;
    char pad38[0x48 - 0x38];
    Node_0010C488 m48;
    Sub_0010C488 m60;
    virtual ~Obj_0010C488() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0010C488::~Obj_0010C488()
{
    func_0010C078(m34, this);
}
