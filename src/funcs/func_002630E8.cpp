extern "C" void* func_001046B0(int size);
/* sym: __13Item_002630E8 = 0x00261078 */
struct Item_002630E8 {
    char pad[0x64];
    Item_002630E8();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Obj_002630E8 {
    char pad[0x2C];
    int m_count;
    int m_ids[3];
    Item_002630E8* m_items[1];
    bool Add(int id);
};

bool Obj_002630E8::Add(int id)
{
    for (int i = 0; i < m_count; i++) {
    }
    m_items[m_count] = new Item_002630E8;
    m_ids[m_count] = id;
    m_count++;
    return true;
}
