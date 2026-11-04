extern "C" void func_00246640(int item);
extern "C" void func_00245430(int item);
extern "C" void func_00245440(int item);
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);

struct Link_00243A70 {
    int m_key;
    int m_value;
    Link_00243A70* m_next;
    Link_00243A70();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Chain_00243A70 {
    int m0;
    int m_count;
    Link_00243A70* m_first;
    Link_00243A70* m_last;
    Link_00243A70* m_cursor;
    int m_pos;
    void Clear();
    bool Append(const int& key, int value);
    int Get(const int& index, int* key);
    void Remove(const int& key);
    int Find(const int& key);
    ~Chain_00243A70();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Set_0023C780 {
    int m0;
    Chain_00243A70 m_items;
    int Count();
    void EachA();
    void EachB();
    void EachC();
};

void Set_0023C780::EachA()
{
    for (int i = 0; i < Count(); i++) {
        int key;
        func_00246640(m_items.Get(i, &key));
    }
}
