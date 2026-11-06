/* sym: _vt$13Link_00189E60 = 0x00361DC0 */

struct Heap_00189E60 {
    char pad[0xEC];
    int mEC;
};

extern Heap_00189E60* D_00388A70;
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_001046B0(int size);

class Link_00189E60 {
public:
    int m0;
    void* m_item;
    int m8;
    Link_00189E60* m_next;
    Link_00189E60* m_prev;

    Link_00189E60(void* item)
    {
        m_item = item;
        m8 = 0;
        m_next = this;
        m_prev = this;
    }
    virtual ~Link_00189E60();
    static void* operator new(unsigned int size) { return func_001046B0(size); }

    Link_00189E60* Valid()
    {
        if (~(int)m_item == 0) return 0;
        return this;
    }
    void Append(Link_00189E60* n)
    {
        n->m_prev = m_prev;
        n->m_next = this;
        m_prev->m_next = n;
        m_prev = n;
    }
};

class Entry_00189E60 {
public:
    int m0;
    Link_00189E60 m_list;

    void Add(void* item);
};

void Entry_00189E60::Add(void* item)
{
    for (Link_00189E60* n = m_list.m_next->Valid(); n; n = n->m_next->Valid()) {
        if (n->m_item == item) {
            return;
        }
    }
    func_0010A950(D_00388A70, D_00388A70->mEC);
    Link_00189E60* n = new Link_00189E60(item);
    func_0010A9B0(D_00388A70);
    m_list.Append(n);
}
