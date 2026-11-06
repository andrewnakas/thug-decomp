/* sym: _vt$13Node_001829A8 = 0x003617C0 */
/* sym: _vt$14Owner_001829A8 = 0x003617D8 */

extern "C" void* func_001046B0(int size);

class Owner_001829A8;

class Node_001829A8 {
public:
    int m0;
    Owner_001829A8* m_owner;
    int m8;
    Node_001829A8* m_prev;
    Node_001829A8* m_next;

    Node_001829A8(Owner_001829A8* owner)
    {
        m_owner = owner;
        m8 = 0;
        m_prev = this;
        m_next = this;
    }
    virtual ~Node_001829A8();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Owner_001829A8 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    Node_001829A8* m_head;

    Owner_001829A8();
    virtual ~Owner_001829A8();
    virtual void P2() = 0;
    virtual void P3() = 0;
};

Owner_001829A8::Owner_001829A8()
{
    m4 = 0;
    mC = 0;
    m_head = new Node_001829A8(this);
}
