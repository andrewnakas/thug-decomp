struct Item_0026ECF0 {
    char m_data[0x1C];
};

extern char D_00391468[];

extern "C" void* func_00104708(unsigned int size);
extern "C" void* func_001046B0(unsigned int size);
extern "C" Item_0026ECF0* func_0026E830(Item_0026ECF0* item);
extern "C" void func_0026DF70(char* dst, const char* src);

struct Table_0026ECF0 {
    int m_0;
    int m_count;
    char* m_name;
    Item_0026ECF0* m_items;
};

Table_0026ECF0* func_0026ECF0(Table_0026ECF0* self, int count)
{
    self->m_count = count;
    int* mem = (int*)func_00104708(count * sizeof(Item_0026ECF0) + 0x10);
    Item_0026ECF0* items = (Item_0026ECF0*)(mem + 4);
    mem[0] = count;
    Item_0026ECF0* p = items;
    for (int i = count - 1; i != -1; i--, p++)
        func_0026E830(p);
    self->m_items = items;
    self->m_name = (char*)func_001046B0(5);
    func_0026DF70(self->m_name, D_00391468);
    return self;
}
