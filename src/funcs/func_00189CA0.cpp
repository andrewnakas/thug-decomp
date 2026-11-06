struct Item_00189CA0 {
    char pad0[0xC];
    Item_00189CA0* mC;
    int m10;
};

struct List_00189CA0 {
    char pad0[0x14];
    Item_00189CA0* m14;
    void Remove(Item_00189CA0* it);
};

void List_00189CA0::Remove(Item_00189CA0* it)
{
    Item_00189CA0* prev = 0;
    for (Item_00189CA0* p = m14; p; p = p->mC) {
        if (p == it) {
            if (prev)
                prev->mC = it->mC;
            else
                m14 = it->mC;
            break;
        }
        prev = p;
    }
    it->m10 = 0;
}
