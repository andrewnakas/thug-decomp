struct Heap_002631C0 {
    char pad0[0x3EC];
    void* m_3EC;
};

struct Item_002631C0;

extern Heap_002631C0* D_00388A70;
extern char D_00390E90[];

extern "C" void func_0010A950(Heap_002631C0* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_002631C0* mgr);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_001046B0(unsigned int size);
extern "C" Item_002631C0* func_00261078(void* mem);
extern "C" void func_00261118(Item_002631C0* item, void* params);
extern "C" void func_002634C8(void* table, unsigned int* key, Item_002631C0* item);

struct Obj_002631C0 {
    int m_0;
    char m_table[4];

    bool Add(void* params);
};

bool Obj_002631C0::Add(void* params)
{
    func_0010A950(D_00388A70, D_00388A70->m_3EC);
    unsigned int key;
    func_001E8A50(params, D_00390E90, &key, 1);
    Item_002631C0* item = func_00261078(func_001046B0(0x64));
    func_00261118(item, params);
    func_002634C8(m_table, &key, item);
    func_0010A9B0(D_00388A70);
    return true;
}
