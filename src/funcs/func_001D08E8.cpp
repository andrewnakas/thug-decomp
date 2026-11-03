extern "C" void* func_001046B0(unsigned int size);
extern "C" int func_001D0E90(void*, int*, int);
extern "C" void* func_001D1AD0(void*, int);
extern "C" void func_001D0DD8(void*, int*, void*);
extern "C" void func_001D1070(void*, int);

struct VtSlot_001D08E8 {
    short delta;
    short pad;
    void (*fn)(void*, int);
};

struct Item_001D08E8 {
    char pad[0x18];
    Item_001D08E8* m_prev;
    Item_001D08E8* m_next;
    char* m_vt;
};

struct Obj_001D08E8 {
    char pad[0xC];
    void* mC;
    Item_001D08E8* m_head;
    void Add(int a, int b, int c);
};

void Obj_001D08E8::Add(int a, int b, int c)
{
    void* mem = func_001046B0(0x2C);
    Item_001D08E8* it = (Item_001D08E8*)func_001D1AD0(mem, func_001D0E90(mC, &a, 1));
    func_001D0DD8(mC, &b, it);
    func_001D1070(it, b);
    VtSlot_001D08E8* s = (VtSlot_001D08E8*)(it->m_vt + 0x40);
    s->fn((char*)it + s->delta, c);
    it->m_next = m_head;
    it->m_prev = m_head->m_prev;
    m_head->m_prev->m_next = it;
    m_head->m_prev = it;
}
