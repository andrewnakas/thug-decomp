extern char D_0038F8A8[];
extern char D_0038F8B0[];
extern char D_0038F8B8[];
extern char D_0038F8C0[];

struct Node_002209E0 {
    void* m_data;
    unsigned int m_pri;
    Node_002209E0* m_prev;
    Node_002209E0* m_next;
    Node_002209E0* GetItem() { return m_pri == 0xFFFFFFFF ? 0 : this; }
};

struct Head_002209E0 {
    void* m_data;
    unsigned int m_pri;
    Node_002209E0* m_prev;
    Node_002209E0* m_next;
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_002209E0* node = m_next;
        Node_002209E0* item;
        while ((item = node->GetItem())) {
            node = item->m_next;
            count++;
        }
        return count;
    }
};

struct Skater_002209E0 {
    char m_pad[0x31C];
    int m_local;
};

struct Mgr_002209E0 {
    char m_pad[0x30];
    Head_002209E0 m_skaters;
};

extern Mgr_002209E0* D_0038FC78;

extern "C" Skater_002209E0* func_0022DE70(Mgr_002209E0* self, unsigned int index);
extern "C" void* func_00203360(Skater_002209E0* skater);
extern "C" void func_002381E0(void* score);
extern "C" void* func_0022E358(Mgr_002209E0* self);
extern "C" unsigned int func_0024F938(void* self);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" int func_002041F8(Skater_002209E0* skater);
extern "C" void func_0012F8A8(const char* name, int heap);

bool func_002209E0()
{
    Mgr_002209E0* mgr = D_0038FC78;
    for (unsigned int i = 0; i < mgr->m_skaters.CountItems(); i++) {
        Skater_002209E0* skater = func_0022DE70(mgr, i);
        if (skater->m_local) {
            func_002381E0(func_00203360(skater));
            if (func_0024F938(func_0022E358(mgr)) == func_001F0D78(D_0038F8A8) || func_0024F938(func_0022E358(mgr)) == func_001F0D78(D_0038F8B0)) {
                func_0012F8A8(D_0038F8B8, func_002041F8(skater));
            } else {
                func_0012F8A8(D_0038F8C0, func_002041F8(skater));
            }
        }
    }
    return true;
}
