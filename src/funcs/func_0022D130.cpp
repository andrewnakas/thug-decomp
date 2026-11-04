extern char D_00372AA0[];

struct Node_0022D130 {
    void* m_data;
    unsigned int m_pri;
    Node_0022D130* m_prev;
    Node_0022D130* m_next;
    Node_0022D130* GetItem() { return m_pri == 0xFFFFFFFF ? 0 : this; }
};

struct Head_0022D130 {
    void* m_data;
    unsigned int m_pri;
    Node_0022D130* m_prev;
    Node_0022D130* m_next;
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_0022D130* node = m_next;
        Node_0022D130* item;
        while ((item = node->GetItem())) {
            node = item->m_next;
            count++;
        }
        return count;
    }
};

struct Skater_0022D130 {
    char m_pad[0x18];
    int m_id;
    char m_pad1C[0x31C - 0x1C];
    int m_local;
};

struct Mgr_0022D130 {
    char m_pad[0x30];
    Head_0022D130 m_skaters;
    char m_pad40[0x398 - 0x40];
    void* m398;
};

extern "C" Skater_0022D130* func_0022DE70(Mgr_0022D130* self, unsigned int index);
extern "C" void* func_0022E358(Mgr_0022D130* self);
extern "C" bool func_0024F8D8(void* self, const char* name);
extern "C" int func_00252270(void* self);
extern "C" void* func_00185578(void* self, unsigned int id);
extern "C" bool func_00290810(void* comp);
extern "C" void func_00290720(void* comp, int a);

bool func_0022D130(Mgr_0022D130* self)
{
    bool done = true;
    for (unsigned int i = 0; i < self->m_skaters.CountItems(); i++) {
        Skater_0022D130* skater = func_0022DE70(self, i);
        if (func_0024F8D8(func_0022E358(self), D_00372AA0) && func_00252270(self->m398) != skater->m_id) {
            continue;
        }
        void* comp = func_00185578(skater, 0xB1D5A3E1);
        if (func_00290810(comp)) {
            continue;
        }
        done = false;
        if (skater->m_local) {
            func_00290720(comp, 0);
        }
    }
    return done;
}
