struct Item_0026E388 {
    char m_data[0x14];
};

extern "C" void* func_00104708(unsigned int size);
extern "C" Item_0026E388* func_0026DF98(Item_0026E388* item);

struct List_0026E388 {
    int m_0;
    int m_count;
    Item_0026E388* m_items;
};

List_0026E388* func_0026E388(List_0026E388* self, int count)
{
    self->m_count = count;
    int* mem = (int*)func_00104708(count * sizeof(Item_0026E388) + 0x10);
    Item_0026E388* items = (Item_0026E388*)(mem + 4);
    mem[0] = count;
    Item_0026E388* p = items;
    for (int i = count - 1; i != -1; i--, p++)
        func_0026DF98(p);
    self->m_items = items;
    return self;
}
