/* sym: _$_13Base_001199F0 = 0x001196D8 */
/* sym: _vt$12Obj_001199F0 = 0x0035C778 */
/* sym: _vt$13Link_001199F0 = 0x0035C700 */
/* sym: _vt$13Node_001199F0 = 0x0035C7C0 */
class Link_001199F0 {
public:
    int m0;
    unsigned int m_data;
    int m8;
    Link_001199F0* m_prev;
    Link_001199F0* m_next;
    virtual void Run();
    virtual ~Link_001199F0()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

class Node_001199F0 : public Link_001199F0 {
public:
    virtual void Run();
    virtual ~Node_001199F0() {}
};

class Base_001199F0 {
public:
    char pad[0x14];
    virtual ~Base_001199F0();
};

class Obj_001199F0;
extern "C" void func_00119D48(Obj_001199F0* self);
extern "C" void func_0011A590(Obj_001199F0* self);

class Obj_001199F0 : public Base_001199F0 {
public:
    char pad18[0x64 - 0x18];
    Node_001199F0 m_node;
    virtual void Update();
    virtual ~Obj_001199F0();
};

Obj_001199F0::~Obj_001199F0()
{
    func_00119D48(this);
    func_0011A590(this);
}
