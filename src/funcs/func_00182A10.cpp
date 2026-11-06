/* sym: _vt$14Owner_001829A8 = 0x003617D8 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Owner_001829A8;

class Node_001829A8 {
public:
    int m0;
    Owner_001829A8* m_owner;
    int m8;
    Node_001829A8* m_prev;
    Node_001829A8* m_next;

    virtual ~Node_001829A8();
};

class Owner_001829A8 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    Node_001829A8* m_head;

    virtual void Key();
    virtual ~Owner_001829A8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Owner_001829A8::~Owner_001829A8()
{
    if (m_head) {
        delete m_head;
    }
}
