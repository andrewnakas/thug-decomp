struct Item_00299830 {
    char pad[0x2C];
    Item_00299830* m2C;
    Item_00299830* m30;
};

struct Obj_00299830;
extern "C" int func_0029C4C0(Obj_00299830* o);
extern "C" void* func_0029C4E0(int size);
extern "C" Item_00299830* func_00298478(void* p);

struct Obj_00299830 {
    char pad[0xC];
    Item_00299830* mC;
    Item_00299830* Add();
};

Item_00299830* Obj_00299830::Add()
{
    if (func_0029C4C0(this) == 400)
        return 0;
    Item_00299830* n = func_00298478(func_0029C4E0(0x40));
    n->m2C = mC;
    if (mC)
        mC->m30 = n;
    n->m30 = 0;
    mC = n;
    return n;
}
