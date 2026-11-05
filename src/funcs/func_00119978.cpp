/* sym: __13Base_00119978 = 0x00119690 */
/* sym: _vt$12Obj_00119978 = 0x0035C778 */
/* sym: _vt$13Node_00119978 = 0x0035C7C0 */
class Link_00119978 {
public:
    int m0;
    unsigned int m_data;
    int m8;
    Link_00119978* m_prev;
    Link_00119978* m_next;
    Link_00119978()
    {
        m_data = 0xFFFFFFFF;
        m8 = 0;
        m_prev = this;
        m_next = this;
    }
    virtual void Run();
};

class Node_00119978 : public Link_00119978 {
public:
    Node_00119978() {}
    virtual void Run();
};

class Base_00119978 {
public:
    char pad[0x14];
    Base_00119978();
    virtual ~Base_00119978();
};

class Obj_00119978 : public Base_00119978 {
public:
    char pad18[0x38 - 0x18];
    int m38;
    char pad3C[0x4C - 0x3C];
    int m4C;
    char pad50[0x60 - 0x50];
    int m60;
    Node_00119978 m_node;
    Obj_00119978(int a);
    virtual void Update();
};

Obj_00119978::Obj_00119978(int a)
{
    m60 = a;
    m38 = 2;
    m4C = 0;
}
