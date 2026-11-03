extern char D_00373018[];
extern char D_00373040[];
extern char D_00373070[];
extern char D_00372B58[];
extern char D_00372B68[];

extern "C" void func_0022C140();

struct List_0022D790 {
    int pad0;
    unsigned int m_pri;
    int m_8;
    List_0022D790* m_next;
    List_0022D790* m_prev;
    void* m_vtbl;
};

struct Handler_0022D790 {
    char pad[0x18];
    void* m_vtbl;
    void (*m_func)();
    void* m_data;
};

struct Slot_0022D790 {
    int m_id;
    int m_c;
    int m_a;
    int m_b;
};

struct Game_0022D790 {
    char pad0[0x14];
    void* m_vtbl;
    Handler_0022D790* m_18;
    char pad1C[8];
    void* m_24;
    void* m_28;
    char pad2C[4];
    List_0022D790 m_list;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    char pad5C[4];
    int m_60;
    int m_64;
    char pad68[0xC];
    void* m_74;
    void* m_78;
    void* m_7C;
    void* m_80;
    void* m_84;
    void* m_88;
    char pad8C[0x308];
    void* m_394;
    void* m_398;
    void* m_39C;
    void* m_3A0;
    int m_3A4;
    char pad3A8[0x14];
    void* m_3BC;
    void* m_3C0;
    Slot_0022D790 m_slots[8];
    int m_444[8];
};

extern "C" void func_001829A8(Game_0022D790* self);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* self, int pri);
extern "C" void func_00230938(Game_0022D790* self);
extern "C" void* func_00262540(void* p);
extern "C" void func_002629E0(void* p);
extern "C" void* func_0024FD60(void* p);
extern "C" void* func_0023B4A0(void* p);
extern "C" void* func_0022E040(Game_0022D790* self);
extern "C" void func_00132478(void* p);
extern "C" void* func_0024EE78(void* p);
extern "C" void* func_00263598(void* p);
extern "C" void* func_00268380(void* p);
extern "C" void* func_00264778(void* p);
extern "C" void* func_00265420(void* p);
extern "C" void func_00266100(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_0022E3E8(Game_0022D790* self, unsigned int key);
extern "C" void* func_00202E60(void* p);
extern "C" void func_00203128(void* p, unsigned int key);
extern "C" void* func_00250B30(void* p, int a);
extern "C" void* func_002521D0(void* p);
extern "C" void* func_0025F300(void* p);
extern "C" void* func_0026ECF0(void* p, int a);
extern "C" void func_0022DC98(Game_0022D790* self, int i, int v);
extern "C" void func_0022DC50(Game_0022D790* self, int i, int v);

static inline void InitHandler_0022D790(Handler_0022D790* h, void (*f)(), void* d)
{
    func_001047F8(h, 0);
    h->m_vtbl = D_00373070;
    h->m_func = f;
    h->m_data = d;
}

Game_0022D790* func_0022D790(Game_0022D790* self)
{
    func_001829A8(self);
    self->m_vtbl = D_00373018;
    List_0022D790* l = &self->m_list;
    l->m_pri = 0xFFFFFFFF;
    l->m_8 = 0;
    l->m_next = l;
    l->m_prev = l;
    l->m_vtbl = D_00373040;
    self->m_54 = 0;
    self->m_58 = 0;
    Handler_0022D790* h = (Handler_0022D790*)func_001046B0(0x24);
    InitHandler_0022D790(h, func_0022C140, self);
    self->m_18 = h;
    func_00230938(self);
    void* p = func_00262540(func_001046B0(0x48));
    self->m_80 = p;
    func_002629E0(p);
    self->m_3BC = func_0024FD60(func_001046B0(0x1C));
    self->m_3C0 = func_0023B4A0(func_001046B0(0x60));
    func_00132478(func_0022E040(self));
    self->m_74 = func_0024EE78(func_001046B0(0x28));
    self->m_24 = func_00263598(func_001046B0(0x674));
    self->m_28 = func_00268380(func_001046B0(0x70));
    self->m_7C = func_00264778(func_001046B0(0x408));
    p = func_00265420(func_001046B0(0x40));
    self->m_78 = p;
    func_00266100(p);
    self->m_48 = 0;
    self->m_4C = 0;
    self->m_50 = 0;
    self->m_60 = 0;
    self->m_64 = 0;
    func_0022E3E8(self, func_001F0D78(D_00372B58));
    self->m_88 = func_00202E60(func_001046B0(0x10));
    func_00203128(self->m_88, func_001F0D78(D_00372B68));
    self->m_394 = func_00250B30(func_001046B0(0x18C), 0);
    self->m_398 = func_002521D0(func_001046B0(0x43C));
    self->m_39C = func_0025F300(func_001046B0(0x130));
    self->m_3A0 = func_0025F300(func_001046B0(0x130));
    self->m_84 = func_0026ECF0(func_001046B0(0x10), 0x15);
    self->m_3A4 = 2;
    for (int i = 0; i < 8; i++) {
        self->m_444[i] = -1;
        self->m_slots[i].m_id = i;
        self->m_slots[i].m_c = 1;
        func_0022DC98(self, i, 1);
        func_0022DC50(self, i, 0);
    }
    self->m_444[0] = 0;
    return self;
}
