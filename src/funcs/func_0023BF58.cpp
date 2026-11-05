struct Item_0023BF58 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3();
};

struct Mgr_0023BF58 {
    int Call(int id);
};

extern "C" Item_0023BF58* func_0023BAD8(Mgr_0023BF58* self, int id, int create);

int Mgr_0023BF58::Call(int id)
{
    Item_0023BF58* item = func_0023BAD8(this, id, 0);
    if (item) {
        return item->V3();
    }
    return 0;
}
