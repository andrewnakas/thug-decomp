/* fuzzy: 98.7 */
/* sym: _vt$12Mgr_001FE5D8 = 0x00366B70 */
/* sym: _vt$14NodeA_001FE5D8 = 0x00366C20 */
/* sym: _vt$14NodeB_001FE5D8 = 0x00366C68 */
/* sym: _vt$14NodeC_001FE5D8 = 0x003668A0 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern char D_00366B10[];

struct Item_001FE5D8 {
    char pad[0x14];
    virtual ~Item_001FE5D8();
};

struct Elem_001FE5D8 {
    char pad[0x14];
    virtual ~Elem_001FE5D8();
};

struct Sub_001FE5D8 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual ~Sub_001FE5D8();
};

#define NODE_001FE5D8(Name)                       \
    struct Name {                                 \
        int m0;                                   \
        Item_001FE5D8* data;                      \
        int m8;                                   \
        Name* m_next;                             \
        Name* m_prev;                             \
        virtual void Update();                    \
        virtual ~Name()                           \
        {                                         \
            m_prev->m_next = m_next;              \
            m_next->m_prev = m_prev;              \
            m_next = this;                        \
            m_prev = this;                        \
        }                                         \
        Item_001FE5D8* GetData() { return data; } \
        Name* Valid() { return (int)data != -1 ? this : 0; } \
    };

NODE_001FE5D8(NodeA_001FE5D8)
NODE_001FE5D8(NodeB_001FE5D8)
NODE_001FE5D8(NodeC_001FE5D8)

struct It_001FE5D8 {
    int m0;
    NodeA_001FE5D8* cur;
    void* vt;
    It_001FE5D8() { vt = D_00366B10; cur = 0; }
    ~It_001FE5D8() { vt = D_00366B10; }
    Item_001FE5D8* Next() {
        cur = cur->m_next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_001FE5D8* Advance(NodeA_001FE5D8* c) {
        cur = c->m_next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_001FE5D8* First(NodeA_001FE5D8* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_001FE5D8 {
    int m0;
    Elem_001FE5D8 m_elems[255];
    char pad17EC[0x1808 - 0x17EC];
    NodeC_001FE5D8 m_1808;
    char pad1820[0x183C - 0x1820];
    Sub_001FE5D8* m_183C;
    Sub_001FE5D8* m_1840;
    Sub_001FE5D8* m_1844;
    Sub_001FE5D8* m_1848;
    char pad184C[0x42D8 - 0x184C];
    NodeB_001FE5D8 m_42D8;
    NodeA_001FE5D8 m_42F0;
    char pad4308[0x4358 - 0x4308];
    virtual void Update();
    virtual ~Mgr_001FE5D8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_001FE5D8::~Mgr_001FE5D8()
{
    It_001FE5D8 it;
    Item_001FE5D8* d = it.First(&m_42F0);
    It_001FE5D8* p = &it;
    while (d) {
        Item_001FE5D8* nx = p->Advance(it.cur);
        delete d;
        d = nx;
    }
    delete m_1840;
    delete m_1844;
    delete m_183C;
    delete m_1848;
}
