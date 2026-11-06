/* fuzzy: 86.3 */
/* near miss: 35 words, register allocation only: game computes &m_list into $a0 then copies to $s0 (count loop reads via $a0), andi in_chrg hoisted to the prologue, and n/this/i in s1/s2/s3 vs mine s3/s1/s2. */
/* sym: _vt$13Node_00265038 = 0x00376078 */
/* sym: _vt$13Base_00265038 = 0x00376048 */
/* sym: _vt$14Group_00265038 = 0x00376018 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Item_00265038 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual ~Item_00265038();
};

class Node_00265038 {
public:
    int m0;
    Item_00265038* m4;
    int m8;
    Node_00265038* mC;
    Node_00265038* m10;
    virtual ~Node_00265038()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Run();
    Node_00265038* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void Remove()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
};

class Head_00265038 {
public:
    Node_00265038 m_node;
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_00265038* p = m_node.mC->Valid(); p; p = p->mC->Valid())
            n++;
        return n;
    }
    Node_00265038* First()
    {
        if (!~(int)m_node.mC->m4)
            return 0;
        return m_node.mC;
    }
    Node_00265038* GetItem(unsigned int idx)
    {
        Node_00265038* p = First();
        while (p) {
            if (idx-- == 0)
                return p;
            p = p->mC->Valid();
        }
        return 0;
    }
    void RemoveAll()
    {
        Node_00265038* p = m_node.mC->Valid();
        while (p) {
            Node_00265038* next = p->mC->Valid();
            p->Remove();
            p = next;
        }
    }
    void DestroyAll()
    {
        unsigned int n = Count();
        for (unsigned int i = 0; i < n; i++) {
            delete GetItem(0)->m4;
        }
        RemoveAll();
    }
    ~Head_00265038() { DestroyAll(); }
};

class Base_00265038 {
public:
    int m0;
    int m4;
    int m8;
    Base_00265038* mC;
    Base_00265038* m10;
    virtual ~Base_00265038()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Run();
};

class Group_00265038 : public Base_00265038 {
public:
    int m18;
    int m1C;
    int m20;
    int m24;
    Head_00265038 m_list;
    virtual void Update();
    virtual ~Group_00265038();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Group_00265038::~Group_00265038()
{
}
