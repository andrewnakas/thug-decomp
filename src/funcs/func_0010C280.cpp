/* sym: _vt$13Node_0010C280 = 0x0035B5C8 */
struct Node_0010C280 {
    int m0;
    void* m_data;
    int m8;
    Node_0010C280* prev;
    Node_0010C280* next;
    Node_0010C280(void* data)
    {
        m_data = data;
        m8 = 0;
        prev = this;
        next = this;
    }
    virtual void Update();
    virtual ~Node_0010C280();
};

struct Link_0010C280 {
    int m0;
    Node_0010C280 node;
    int m1C;
    Link_0010C280();
};

Link_0010C280::Link_0010C280()
    : node(this)
{
    m1C = 0;
}
