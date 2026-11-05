struct Link_00244170 {
    int m_id;
    Link_00244170* m_next;
};

struct Item_00244170 {
    char pad[0x1C];
    unsigned int m_1C;
    char pad20[0x2C - 0x20];
    Link_00244170* m_2C;
    void Spread(int depth);
};

extern "C" void* func_00240850();
extern "C" Item_00244170* func_0023BAD8(void* owner, int id, int create);

void Item_00244170::Spread(int depth)
{
    void* owner = func_00240850();
    for (Link_00244170* l = m_2C; l && l->m_id; l = l->m_next) {
        Item_00244170* c = func_0023BAD8(owner, l->m_id, 1);
        if (c) {
            c->m_1C |= m_1C;
            c->Spread(depth + 1);
        }
    }
}
