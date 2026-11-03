extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" void func_001F4FA8(void* p, unsigned int id);
extern "C" void func_002919B0(void* p);
extern "C" void func_00184AB0(void* obj, unsigned int a, void* b);
extern "C" void func_001E7360(void* dst, int a, void* src);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" int func_001EFDC0(void* p);

struct Ped_001ADF90 {
    int m_pad[23];
    unsigned short m5C;
};

struct Skater_001ADF90 {
    int m_pad[167];
    Ped_001ADF90* m29C;
};

struct Script_001ADF90 {
    int m_pad[6];
    void* m18;
};

struct Obj_001ADF90 {
    int m_pad[5];
    Script_001ADF90* m14;
};

struct Flag_001ADF90 {
    int m_pad[78];
    int m138;
};

static inline short GetIndex_001ADF90(Ped_001ADF90* ped)
{
    if (ped) return ped->m5C;
    return -1;
}

struct C_001ADF90 {
    int m_pad[3];
    Obj_001ADF90* mC;
    int m10[3];
    int m1C;
    int m20[3];
    Skater_001ADF90* m2C;
    void* m30;
    Flag_001ADF90* m34;
    void* m38;
    int m3C[1167];
    int m1278;
    int m127C[12];
    int m12AC;
    int m12B0[17];
    int m12F4;
    int Start(void* p, void* extra, void* params);
};

extern "C" int func_001B0E78(C_001ADF90* self);

int C_001ADF90::Start(void* p, void* extra, void* params)
{
    unsigned int id = 0;
    func_001E8398(p, 0xA6D2D890, &id, 0);
    if (id == 0x255ED86F) {
        if (GetIndex_001ADF90(m2C->m29C) == -1) return 0;
    }
    void* w;
    if (func_001E8180(p, 0x7031F10C, &w, 0)) {
        if (!func_001E8618(w, 0x7A16ACA0)) func_001F4FA8(m38, id);
    }
    if (id) {
        m12AC = 0;
        m12F4 = 0;
        m1278 = 0;
        m1C++;
        void* w2 = 0;
        func_001E8180(p, 0x7031F10C, &w2, 0);
        func_002919B0(m30);
        Obj_001ADF90* o = mC;
        func_00184AB0(o, id, w2);
        if (extra) func_001E7360(o->m14->m18, 0, extra);
        func_001E6AC8(o->m14->m18, params);
        func_001EFDC0(o->m14);
        m34->m138 = 1;
        func_001B0E78(this);
        m1C--;
        return 1;
    }
    return 0;
}
