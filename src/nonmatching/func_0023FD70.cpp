/* fuzzy: 81.9 */
struct Link_0023FD70 {
    int m_id;
    Link_0023FD70* m_next;
};

struct Item_0023FD70 {
    char pad[0x2C];
    Link_0023FD70* m_2C;
    Link_0023FD70* m_30;
};

static inline int Count_0023FD70(Link_0023FD70* head)
{
    if (!head->m_id)
        return 0;
    int n = 0;
    for (Link_0023FD70* p = head; p && p->m_id; p = p->m_next)
        n++;
    return n;
}

struct Mgr_0023FD70;

extern "C" int func_0023C040(Mgr_0023FD70* self);
extern "C" Item_0023FD70* func_00243C18(void* chain, const int* index, int* key);
extern "C" int func_00246258(Item_0023FD70* self);
extern "C" Item_0023FD70* func_0023BAD8(Mgr_0023FD70* self, int id, int create);
extern "C" void func_00244040(Item_0023FD70* self, int id);
extern "C" void func_00244170(Item_0023FD70* self, int depth);

struct Mgr_0023FD70 {
    int m0;
    char m4[0x18];
    void Link();
};

void Mgr_0023FD70::Link()
{
    int n = func_0023C040(this);
    for (int i = 0; i < n; i++) {
        int key;
        Item_0023FD70* item = func_00243C18(m4, &i, &key);
        int id = func_00246258(item);
        Link_0023FD70* l = item->m_2C;
        while (l) {
            if (!l->m_id)
                break;
            Item_0023FD70* c = func_0023BAD8(this, l->m_id, 0);
            bool found = false;
            for (Link_0023FD70* p = c->m_30; p && p->m_id; p = p->m_next) {
                if (p->m_id == id) {
                    found = true;
                    break;
                }
            }
            if (!found)
                func_00244040(c, id);
            l = l->m_next;
        }
    }
    for (int i = 0; i < n; i++) {
        int key;
        Item_0023FD70* item = func_00243C18(m4, &i, &key);
        if (!item->m_30->m_id)
            func_00244170(item, 0);
    }
    for (int i = 0; i < n; i++) {
        int key;
        Item_0023FD70* item = func_00243C18(m4, &i, &key);
        int out = Count_0023FD70(item->m_2C);
        int in = Count_0023FD70(item->m_30);
    }
}
