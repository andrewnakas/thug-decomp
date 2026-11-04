struct Comp_002AB228 {
    char pad[0x18];
    virtual void A();
    virtual void B();
    virtual ~Comp_002AB228();
};

struct Item_002AB228 {
    char pad[0x14C];
    unsigned int m14C;
    char pad2[0x168 - 0x150];
    Comp_002AB228* m168;
};

struct S_002AB228 {
    char pad[0xB4];
    Comp_002AB228* mB4;
};

extern S_002AB228* D_00392068;
extern "C" Item_002AB228* func_002A56E0(S_002AB228* s);
extern "C" int func_002B1FF8(Item_002AB228* it);
extern "C" void func_002A4A58(S_002AB228* s, Item_002AB228* it);

bool func_002AB228()
{
    S_002AB228* s = D_00392068;
    Item_002AB228* it = func_002A56E0(s);
    if (!it)
        return false;
    if (!func_002B1FF8(it))
        return true;
    func_002A4A58(s, it);
    if (it->m168)
        delete it->m168;
    it->m168 = 0;
    if (s->mB4)
        delete s->mB4;
    s->mB4 = 0;
    it->m14C &= ~0x10000;
    return true;
}
