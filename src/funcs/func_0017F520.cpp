struct Item_0017F520 {
    char pad0[0x14];
    Item_0017F520* m14;
};

void func_0017F520(Item_0017F520* item, Item_0017F520** head)
{
    if (!*head) {
        item->m14 = 0;
        *head = item;
        return;
    }
    Item_0017F520* p = *head;
    while (p->m14)
        p = p->m14;
    item->m14 = p->m14;
    p->m14 = item;
}
