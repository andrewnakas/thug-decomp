/* sym: _vt$12Obj_0025F368 = 0x00375888 */
/* sym: _vt$13Node_0025F368 = 0x00375768 */
/* sym: _$_13Base_0025F368 = 0x00183D80 */
/* sym: _$_12Mem_0025F368 = 0x00114D00 */
extern "C" int func_0025F460(void* self);

struct Base_0025F368 {
    int m0;
    int m4;
    virtual ~Base_0025F368();
};

struct Node_0025F368 {
    int m0;
    int m4;
    int m8;
    Node_0025F368* m_next;
    Node_0025F368* m_prev;
    virtual void Update();
    virtual ~Node_0025F368()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Mem_0025F368 {
    int m0;
    ~Mem_0025F368();
};

struct Obj_0025F368 : Base_0025F368 {
    char padC[0x48 - 0xC];
    Node_0025F368 m_node;
    Mem_0025F368 m_mem;
    virtual void Update();
    virtual ~Obj_0025F368();
};

Obj_0025F368::~Obj_0025F368()
{
    func_0025F460(this);
}
