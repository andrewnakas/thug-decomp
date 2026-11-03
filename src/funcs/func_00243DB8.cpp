struct Game_00243DB8 {
    char pad0[0x24];
    int m_level;
};

struct Obj_00243DB8 {
    int m0;
    Obj_00243DB8* m_data;
    int m_pri;
    Obj_00243DB8* m_prev;
    Obj_00243DB8* m_next;
    void* m_vt;
    void* m18;
    unsigned int m_flags;
    void* m_params;
    void* m24;
    int m28;
    void* m2C;
    void* m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int pad58;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int pad8C;
    int m90;
    int pad94;
    int m98;
    int pad9C;
    int mA0;
};

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00243D70(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* s, void* params);
extern "C" void* func_002488D0(void* p, void* params);
extern "C" int func_00263930(int level);
extern "C" void func_002440B0(Obj_00243DB8* self, void* params);
extern "C" bool func_001E8708(void* params, unsigned int name);

extern void* D_00388A70;
extern Game_00243DB8* D_0038FC78;
extern char D_00373B00[];

static inline void Reset_00243DB8(Obj_00243DB8* self)
{
    self->m90 = 0;
    self->m74 = 0;
    self->m98 = 0;
    self->mA0 = 1;
    self->m78 = 0;
    self->m7C = 0;
    self->m38 = 0;
    self->m3C = 0;
    self->m80 = 0;
    self->m70 = 0;
    self->m40 = 0;
    self->m44 = 0;
    self->m48 = 0;
    self->m88 = 1;
    self->m54 = 0;
    self->m6C = -1;
    self->m68 = -1;
}

Obj_00243DB8* Construct_00243DB8(Obj_00243DB8* self, void* params)
{
    self->m_data = self;
    self->m_pri = 0;
    self->m_prev = self;
    self->m_next = self;
    self->m38 = 0;
    self->m3C = 0;
    self->m_vt = D_00373B00;
    self->m2C = func_00243D70(func_0010A638(D_00388A70, 0xC, 1, 0));
    self->m30 = func_00243D70(func_0010A638(D_00388A70, 0xC, 1, 0));
    Reset_00243DB8(self);
    self->m_params = func_001E6978(func_001190D0(8));
    func_001E6AC8(self->m_params, params);
    self->m18 = func_002488D0(func_0010A638(D_00388A70, 0x14, 1, 0), self->m_params);
    self->m24 = func_001E6978(func_001190D0(8));
    self->m5C = 0;
    self->m4C = 0x7FFFFFFF;
    self->m60 = 0;
    self->m64 = 0;
    self->m50 = 0;
    self->m28 = 0;
    self->m34 = func_00263930(D_0038FC78->m_level);
    func_002440B0(self, params);
    if (func_001E8708(params, 0x04AB5F14)) {
        self->m_flags |= 2;
    }
    if (func_001E8708(params, 0xC6B4258F)) {
        self->m_flags |= 4;
    }
    if (func_001E8708(params, 0x8A3A324E) || func_001E8708(params, 0xD303A1A3)) {
        self->m84 = 1;
    } else {
        self->m84 = 0;
    }
    return self;
}
