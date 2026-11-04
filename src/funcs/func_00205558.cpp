/* sym: _$_13Base_00205558 = 0x00256980 */
/* sym: _$_12Mem_00205558 = 0x001040A8 */
/* sym: _vt$13Node_00205558 = 0x00366F50 */
/* sym: _vt$13Objt_00205558 = 0x00366EB0 */

struct Base_00205558 {
    int m_0;
    int m_4;
    virtual void Update();
    virtual ~Base_00205558();
};

struct Mem_00205558 {
    char pad[0x94];
    ~Mem_00205558();
};

struct Elem_00205558 {
    int m_0;
    int m_4;
    int m_8;
    virtual ~Elem_00205558();
};

struct Node_00205558 {
    int m_0;
    int m_4;
    int m_8;
    Node_00205558* m_next;
    Node_00205558* m_prev;
    virtual void Run();
    virtual ~Node_00205558()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Inner_00205558 {
    char pad[0x20];
    int m_20;
};

struct Model_00205558 {
    char pad[0x51C];
    Inner_00205558* m_51C;
};

extern "C" void func_00107F18(int h);
extern "C" void func_00107FB0(int h);
extern "C" void func_002057E8(void* self);
extern "C" void func_001F0210(unsigned int script, void* params, void* obj, void* a, int b);
extern "C" void* func_00203EE0(void* self);
extern "C" void func_00184950(void* p);

struct Objt_00205558 : Base_00205558 {
    char pad0C[0x150 - 0xC];
    int m_150;
    char pad154[0x1B4 - 0x154];
    Mem_00205558 m_mem;
    char pad248[0x248 - 0x1B4 - sizeof(Mem_00205558)];
    Elem_00205558* m_elems[11];
    char pad274[0x298 - 0x274];
    Node_00205558 m_node;
    char pad2B0[0x2C8 - 0x2B0];
    Model_00205558* m_model;
    char pad2CC[0x31C - 0x2CC];
    int m_31C;
    int m_320;

    virtual void Update();
    virtual ~Objt_00205558();
};

Objt_00205558::~Objt_00205558()
{
    if (m_150 && m_31C && m_model) {
        func_00107F18(m_model->m_51C->m_20);
        func_00107FB0(m_model->m_51C->m_20);
    }
    func_002057E8(this);
    func_001F0210(0xF429E0AC, 0, this, 0, 0);
    for (int i = 0; i < 11; i++) {
        if (m_elems[i]) {
            delete m_elems[i];
        }
    }
    if (m_31C && m_320 == 1) {
        void* p = func_00203EE0(this);
        if (p) {
            func_00184950(p);
        }
    }
}
