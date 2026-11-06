/* sym: _vt$12Mgr_001F2D50 = 0x003660C0 */
/* sym: _$_13Base_001F2D50 = 0x00182A10 */
/* sym: _$_14Entry_001F2D50 = 0x001F2C88 */
struct Entry_001F2D50 {
    int m0;
    char m4[0x10 - 4];
    int m10;
    int m14;
    ~Entry_001F2D50();
};

extern "C" void func_001F3390(void* list);
extern "C" Entry_001F2D50* func_001F33A0(void* list, int a);
extern "C" void func_001F3450(void* list, void* node);
extern "C" void func_001F35C0(void* list, int flags);

struct Base_001F2D50 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void Update();
    virtual ~Base_001F2D50();
};

struct Mgr_001F2D50 : Base_001F2D50 {
    void* m_list;
    virtual void Update();
    virtual ~Mgr_001F2D50();
};

static inline void Remove_001F2D50(void* list, Entry_001F2D50* e)
{
    func_001F3450(list, e->m4);
    e->m10 = 0;
    e->m14 = 0;
    delete e;
}

Mgr_001F2D50::~Mgr_001F2D50()
{
    func_001F3390(m_list);
    for (Entry_001F2D50* e = func_001F33A0(m_list, 0); e; e = func_001F33A0(m_list, 0))
        Remove_001F2D50(m_list, e);
    if (m_list)
        func_001F35C0(m_list, 3);
}
