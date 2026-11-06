struct Link_00187B20 {
    char pad[0xC];
    Link_00187B20* mC;
    Link_00187B20* m10;
};
struct Item_00187B20 {
    char pad[0x2C];
    Link_00187B20 m2C;
};
struct Obj_00187B20 {
    char pad[0x30];
    Link_00187B20 m30;
    void Add(Item_00187B20* o);
};

void Obj_00187B20::Add(Item_00187B20* o)
{
    Link_00187B20* h = &m30;
    Link_00187B20* n = &o->m2C;
    n->m10 = h;
    n->mC = h->mC;
    h->mC->m10 = n;
    h->mC = n;
}
