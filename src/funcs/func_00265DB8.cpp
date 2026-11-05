struct Ids_00265DB8 {
    int m_items[32];
    unsigned int m_count;
};

struct Item_00265DB8 {
    char pad[0x18];
    int m18;
    char pad2[0x24 - 0x1C];
    int m24;
};

void Collect_00265DB8(Item_00265DB8* it, Ids_00265DB8* ids)
{
    if (ids->m_count < 32 && !it->m24) {
        ids->m_items[ids->m_count] = it->m18;
        ids->m_count++;
    }
}
