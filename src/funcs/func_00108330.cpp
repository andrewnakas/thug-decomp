/* sym: _$_18HashTable_00108330 = 0x00109A80 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00108180(void* item, void* data);

struct HashTable_00108330 {
    int m0;
    void* m4;
    ~HashTable_00108330();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_00109CC0(HashTable_00108330* self, void (*fn)(void*, void*), void* data);
extern "C" void func_001099C8(HashTable_00108330* self);

struct Obj_00108330 {
    int m0;
    void* m4;
    int m8;
    HashTable_00108330* m_table;
    ~Obj_00108330();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00108330::~Obj_00108330()
{
    func_0010A8D8(D_00388A70, m4);
    func_00109CC0(m_table, func_00108180, 0);
    func_001099C8(m_table);
    delete m_table;
}
