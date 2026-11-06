/* sym: _vt$13Link_00189D80 = 0x00361DC0 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Link_00189D80 {
public:
    int m0;
    void* m_item;
    int m8;
    Link_00189D80* m_next;
    Link_00189D80* m_prev;

    virtual void Key();
    virtual ~Link_00189D80()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    bool Empty() { return m_prev == this; }
};

class Entry_00189D80 {
public:
    int m0;
    Link_00189D80 m_list;

    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" Entry_00189D80* func_0018AE38(void* table, int* key, int a);
extern "C" void func_0018AF58(void* table, int* key);
extern "C" void func_00189F18(Entry_00189D80* e, void* item);

class Mgr_00189D80 {
public:
    char pad0[0x10];
    void* m_table;

    void Unregister(int key, void* item);
};

void Mgr_00189D80::Unregister(int key, void* item)
{
    Entry_00189D80* e = func_0018AE38(m_table, &key, 1);
    if (!e) {
        return;
    }
    func_00189F18(e, item);
    if (e->m_list.Empty()) {
        func_0018AF58(m_table, &key);
        delete e;
    }
}
