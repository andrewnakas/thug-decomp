/* sym: _vt$13Node_0010C2B0 = 0x0035B5C8 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Node_0010C2B0 {
    int m0;
    int m4;
    int m8;
    Node_0010C2B0* prev;
    Node_0010C2B0* next;
    virtual void Update();
    virtual ~Node_0010C2B0()
    {
        next->prev = prev;
        prev->next = next;
        prev = this;
        next = this;
    }
};

struct Link_0010C2B0 {
    int m0;
    Node_0010C2B0 node;
    ~Link_0010C2B0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Link_0010C2B0::~Link_0010C2B0()
{
}
