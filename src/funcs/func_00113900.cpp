/* sym: _vt$12Obj_00113900 = 0x0035C0C8 */
struct Node_00113900 {
    int m0;
    void* m_data;
    int m8;
    Node_00113900* prev;
    Node_00113900* next;
    Node_00113900(void* data)
    {
        m_data = data;
        m8 = 0;
        prev = this;
        next = this;
    }
    virtual void Update();
};

class Obj_00113900 : public Node_00113900 {
public:
    char pad[0x38];
    int m50;
    int m54;
    Obj_00113900(int a, int b);
    virtual void Update();
};

Obj_00113900::Obj_00113900(int a, int b)
    : Node_00113900(this)
{
    m50 = a;
    m54 = b;
}
