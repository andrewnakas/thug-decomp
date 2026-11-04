/* sym: _vt$13Item_0025E768 = 0x003757E8 */
/* sym: _$_12Obj_0025E768 = 0x0025A8E0 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern void* D_0038DB38;
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void* func_001D05B0(void* mgr, int id, int a);
extern "C" void func_001D04E0(void* mgr, void* p);
extern "C" void func_00135EE8(float f);
extern "C" void func_00135EF8(int i, float f);

struct Node_0025E768 {
    int m0;
    int m4;
    int m8;
    Node_0025E768* m_next;
    Node_0025E768* m_prev;
    virtual void Update();
    virtual ~Node_0025E768()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Obj_0025E768 : Node_0025E768 {
    void* m18;
    char pad1C[0x38 - 0x1C];
    void* m38;
    virtual void Update();
    virtual ~Obj_0025E768();
};

struct Item_0025E768 : Obj_0025E768 {
    int m3C;
    int m40;
    char pad44[0x50 - 0x44];
    void* m50;
    float m54;
    float m58;
    float m5C;
    void* m60;
    virtual void Update();
    virtual ~Item_0025E768();
};

Item_0025E768::~Item_0025E768()
{
    if (m50)
        func_001E6AE8(m50, 3);
    if (m3C) {
        void* mgr = D_0038DB38;
        func_001D04E0(mgr, func_001D05B0(mgr, m40, 1));
        m3C = 0;
    }
    if (m60) {
        func_0010A8D8(D_00388A70, m60);
        m60 = 0;
    }
    func_00135EE8(m54);
    func_00135EF8(0, m58);
    func_00135EF8(1, m5C);
}
