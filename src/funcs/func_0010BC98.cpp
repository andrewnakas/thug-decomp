extern "C" void* func_00331A9C(char*, const char*);
extern "C" void* func_001046B0(int);

class Region_0010BC98 {
public:
    char pad[0x18];
    virtual ~Region_0010BC98();
    Region_0010BC98(int size);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Slot_0010BC98 {
    Region_0010BC98* m_region;
    void* m_heap;
    int m_id;
    char m_name[0x80];
    int m_used;
};

struct Mem_0010BC98 {
    char pad[0x1A8];
    Slot_0010BC98 m_slots[4];
    void AddHeap(int id, int size, const char* name);
};

extern "C" void* func_0010AF60(Mem_0010BC98*, void*, int, const char*);

void Mem_0010BC98::AddHeap(int id, int size, const char* name)
{
    Slot_0010BC98* slot = 0;
    for (int i = 0; i < 4; i++) {
        if (!m_slots[i].m_used) {
            slot = &m_slots[i];
            break;
        }
    }
    slot->m_id = id;
    func_00331A9C(slot->m_name, name);
    slot->m_region = new Region_0010BC98(size);
    slot->m_heap = func_0010AF60(this, slot->m_region, 1, slot->m_name);
    slot->m_used = 1;
}
