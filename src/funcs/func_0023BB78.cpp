class Base_0023BB78 {
public:
    char pad0[0x14];
    virtual ~Base_0023BB78();
};

class Entry_0023BB78 : public Base_0023BB78 {
public:
    void* m_18;
};

extern "C" Entry_0023BB78* func_00243BC8(void* table, int* key);
extern "C" void func_00243CD0(void* table, int* key);
extern "C" void func_00249DC8(void* p);

struct Mgr_0023BB78 {
    int m_0;
    char m_table[0x1C];
    int m_current;

    bool Remove(int id);
};

bool Mgr_0023BB78::Remove(int id)
{
    int key = id;
    Entry_0023BB78* e = func_00243BC8(m_table, &key);
    func_00249DC8(e->m_18);
    key = id;
    func_00243CD0(m_table, &key);
    if (m_current == id)
        m_current = 0;
    delete e;
    return true;
}
