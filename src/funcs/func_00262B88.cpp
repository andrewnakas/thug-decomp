struct Heap_00262B88 {
    char pad0[0x3EC];
    void* m_3EC;
};

struct Item_00262B88;

extern Heap_00262B88* D_00388A70;
extern char D_00375C18[];

extern "C" void func_0010A950(Heap_00262B88* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_00262B88* mgr);
extern "C" Item_00262B88* func_00263320(void* table, unsigned int* index, int* out);
extern "C" bool func_002623B8(Item_00262B88* item);
extern "C" void* func_00262388(Item_00262B88* item);
extern "C" void func_00261D48(Item_00262B88* item, void* data, void* params);
extern "C" bool func_001E84E8(void* params, const char* name, int* out, int required);

struct Obj_00262B88 {
    char pad0[4];
    char m_table[4];
    unsigned int m_count;

    void Load(void* params);
};

extern "C" void func_002628F8(Obj_00262B88* self, int mode);

void Obj_00262B88::Load(void* params)
{
    func_0010A950(D_00388A70, D_00388A70->m_3EC);
    unsigned int count = m_count;
    for (unsigned int i = 0; i < count; i++) {
        unsigned int index = i;
        int out;
        Item_00262B88* item = func_00263320(m_table, &index, &out);
        if (func_002623B8(item))
            func_00261D48(item, func_00262388(item), params);
    }
    int mode = 0;
    func_001E84E8(params, D_00375C18, &mode, 0);
    func_002628F8(this, mode);
    func_0010A9B0(D_00388A70);
}
