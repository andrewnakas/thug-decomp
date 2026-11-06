struct Link_002442B8 {
    int m_id;
    Link_002442B8* m_next;
    int m_8;
};

struct Item_002442B8 {
    char pad[0x2C];
    Link_002442B8* m_2C;
    void Reset();
};

extern "C" void* func_00240850();
extern "C" Item_002442B8* func_0023BAD8(void* owner, int id, int create);

void Item_002442B8::Reset()
{
    void* owner = func_00240850();
    for (Link_002442B8* l = m_2C; l && l->m_id; l = l->m_next) {
        l->m_8 = 0;
        Item_002442B8* c = func_0023BAD8(owner, l->m_id, 1);
        if (c) {
            c->Reset();
        }
    }
}
