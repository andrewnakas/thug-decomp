struct Heap_002628F8 {
    char pad0[0x3EC];
    void* m_3EC;
};

struct Item_002628F8;

extern Heap_002628F8* D_00388A70;

extern "C" void func_0010A950(Heap_002628F8* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_002628F8* mgr);
extern "C" void func_002610C0(Item_002628F8* item, Item_002628F8* src);

struct Obj_002628F8 {
    char pad0[0x1C];
    Item_002628F8* m_items[2];
    int m_mode;

    void SetMode(unsigned int id);
};

extern "C" Item_002628F8* func_002629B8(Obj_002628F8* self, unsigned int id);

void Obj_002628F8::SetMode(unsigned int id)
{
    func_0010A950(D_00388A70, D_00388A70->m_3EC);
    if (!m_mode) {
        m_items[m_mode] = func_002629B8(this, id);
    } else {
        Item_002628F8** slot = m_items;
        slot += m_mode;
        func_002610C0(*slot, func_002629B8(this, id));
    }
    func_0010A9B0(D_00388A70);
}
