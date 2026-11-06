struct Item_0017F578 {
    char pad0[0x14];
    Item_0017F578* m14;
};

void func_0017F578(Item_0017F578* item, Item_0017F578** head)
{
    if (*head == item) {
        *head = item->m14;
    } else if (*head) {
        for (Item_0017F578* p = *head; p->m14; p = p->m14) {
            if (p->m14 == item) {
                p->m14 = item->m14;
                break;
            }
        }
    }
}
