struct Item_0023D500 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3();
};

struct Mgr_0023D500 {
    void Call(int id);
};

extern "C" Item_0023D500* func_0023BAD8(Mgr_0023D500* self, int id, int create);
extern "C" void func_002463A8(Item_0023D500* item);

void Mgr_0023D500::Call(int id)
{
    Item_0023D500* item = func_0023BAD8(this, id, 1);
    if (item->V3()) {
        func_002463A8(item);
    }
}
