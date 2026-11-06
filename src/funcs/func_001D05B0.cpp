struct Item_001D05B0 {
    char m_pad0[0x20];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int IsReady();
};

extern "C" Item_001D05B0* func_001D0E90(void* table, int* key, int create);
extern "C" void func_0010ED38(int a);

struct Obj_001D05B0 {
    char m_pad0[0xC];
    void* m_table;
    Item_001D05B0* Get(int key);
};

Item_001D05B0* Obj_001D05B0::Get(int key)
{
    Item_001D05B0* o = func_001D0E90(m_table, &key, 1);
    if (o && !o->IsReady()) {
        while (!o->IsReady())
            func_0010ED38(0);
    }
    return o;
}
