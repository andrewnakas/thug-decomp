extern "C" void* func_00265EA0(void* self, int id);

struct Item_00265778 {
    char pad[0x18];
    void* m18;
};

void* Get_00265778(void* self, int id)
{
    Item_00265778* p = (Item_00265778*)func_00265EA0(self, id);
    if (p)
        return p->m18;
    return 0;
}
