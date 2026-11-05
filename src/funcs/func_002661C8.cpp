struct Ctx_002661C8 {
    int m_target;
    unsigned char m_index;
    int m_found;
};

struct Item_002661C8 {
    char pad[0x18];
    int m18;
};

void Visit_002661C8(Item_002661C8* it, Ctx_002661C8* c)
{
    if (c->m_found)
        return;
    if (c->m_target == it->m18) {
        c->m_found = 1;
        return;
    }
    c->m_index++;
}
