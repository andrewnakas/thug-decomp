struct Item_0023BF98 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3();
};

struct Mgr_0023BF98 {
    int m0;
    char m_4[0x18];
    int Find(int flag);
};

extern "C" int func_0023C040(Mgr_0023BF98* self);
extern "C" Item_0023BF98* func_00243C18(void* list, int* index, int* out);
extern "C" int func_00246C60(Item_0023BF98* item);

int Mgr_0023BF98::Find(int flag)
{
    int i = 0;
    int tmp;
    while (i < func_0023C040(this)) {
        Item_0023BF98* item = func_00243C18(m_4, &i, &tmp);
        if (!flag || !func_00246C60(item)) {
            if (item->V3()) {
                return i;
            }
        }
        i++;
    }
    return -1;
}
