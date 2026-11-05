struct Node_0022C140 {
    void* m_key;
    unsigned int m_item;
    Node_0022C140* m_prev;
    Node_0022C140* m_next;
    Node_0022C140* GetItem() { return m_item == 0xFFFFFFFF ? 0 : this; }
};

struct Head_0022C140 {
    void* m_key;
    unsigned int m_item;
    Node_0022C140* m_prev;
    Node_0022C140* m_next;
    Node_0022C140* FirstItem()
    {
        if (!~m_next->m_item) {
            return 0;
        }
        return m_next;
    }
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_0022C140* item = m_next->GetItem();
        while (item) {
            item = item->m_next->GetItem();
            count++;
        }
        return count;
    }
    Node_0022C140* GetItem(unsigned int index)
    {
        Node_0022C140* item = FirstItem();
        while (item) {
            if (index-- == 0) {
                return item;
            }
            item = item->m_next->GetItem();
        }
        return 0;
    }
};

struct Mgr_0022C140 {
    char m_pad[0x30];
    Head_0022C140 m_list;
};

struct Info_0022C140 {
    char pad[0x150];
    int m_150;
};

struct Player_0022C140 {
    char pad[0x18];
    Info_0022C140* m_18;
    char pad1C[0x30 - 0x1C];
    int m_30;
};

struct Obj_0022C140 {
    char pad[0x20];
    Mgr_0022C140* m_20;
    void Update();
};

extern void* D_00392068;
extern char D_00372828[];
extern "C" void func_0022D3F0(Mgr_0022C140* mgr);
extern "C" bool func_002A1A38(void* net);
extern "C" void func_0022EBB0(Mgr_0022C140* mgr);
extern "C" void* func_0022E358(Mgr_0022C140* mgr);
extern "C" bool func_0024F860(void* a);
extern "C" unsigned int func_0024F938(void* a);
extern "C" bool func_0024F050(void* a);
extern "C" Player_0022C140* func_002A5820(void* net);
extern "C" void* func_00203360(Info_0022C140* info);
extern "C" int func_002392B8(void* s);
extern "C" float func_0010FAB8();
extern "C" void func_00239198(void* s, int v);
extern "C" int func_0024F628(void* a);
extern "C" bool func_0024F540(void* a);
extern "C" int func_002B0FB8(void* net, int v);
extern "C" void func_0022D338(Mgr_0022C140* mgr, float t, float reset, float rate, char* script);

void Obj_0022C140::Update()
{
    Mgr_0022C140* mgr = m_20;
    void* net = D_00392068;
    func_0022D3F0(mgr);
    if (func_002A1A38(net) && mgr->m_list.CountItems()) {
        func_0022EBB0(mgr);
    }
    if (func_0024F860(func_0022E358(mgr))) {
        return;
    }
    if (func_0024F938(func_0022E358(mgr)) != 0x6EF8FDA0 && func_0024F938(func_0022E358(mgr)) != 0x5D32129C) {
        return;
    }
    if (func_0024F050(func_0022E358(mgr))) {
        return;
    }
    Player_0022C140* p = func_002A5820(net);
    if (!p) {
        return;
    }
    Info_0022C140* info = p->m_18;
    if (info->m_150) {
        return;
    }
    void* s = func_00203360(info);
    int base = func_002392B8(s);
    func_00239198(s, base + (int)(func_0010FAB8() * 1000.00006f));
    int total = func_0024F628(func_0022E358(mgr));
    int used;
    if (func_0024F540(func_0022E358(mgr))) {
        used = func_002B0FB8(net, p->m_30);
    } else {
        used = func_002392B8(s);
    }
    func_0022D338(mgr, (float)(total - used) * 0.001f, 10.0f, 10.0f, D_00372828);
}
