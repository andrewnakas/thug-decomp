struct Item_00187678 {
    char pad[0x18];
    int m18;
    char pad2[0x34 - 0x1C];
    int m34;
};
struct Obj_00187678 {
    char pad[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3(Item_00187678* it, int v);
    void Run(Item_00187678* it, int v);
};

void Obj_00187678::Run(Item_00187678* it, int v)
{
    it->m34 = v;
    V3(it, it->m18);
}
