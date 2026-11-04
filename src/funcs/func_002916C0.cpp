struct Skater_002916C0 {
    char pad0[0x164];
    int m164;
};

struct State_002916C0 {
    char pad0[0x34];
    int m34;
};

struct Owner_002916C0 {
    char pad0[0xC];
    Skater_002916C0* mC;
    char pad10[0x5B0 - 0x10];
    State_002916C0* m5B0;
};

struct Info_002916C0 {
    char pad0[0x18];
    int m18;
};

extern "C" void func_002919B0(void* p);
extern "C" void func_00291A78(void* p);
extern "C" void func_0027C928(void* p);
extern "C" void* func_002A52F0(void* table, unsigned short id);
extern "C" int func_002B30A0(void* p);
extern "C" int* func_002A39E0(void* s, int v);
extern "C" int func_001E8708(void* p, unsigned int key);
extern "C" int func_002918E0(void* self, int a, int b, int c, int d);
extern void* D_00392068;

struct Comp_002916C0 {
    char pad0[0xC];
    Info_002916C0* mC;
    char pad10[0x1C - 0x10];
    int m1C;
    int m20;
    int m24;
    int m28;
    char pad2C[0x34 - 0x2C];
    Owner_002916C0* m34;
    int CallMember(unsigned int name, void* params);
};

int Comp_002916C0::CallMember(unsigned int name, void* params)
{
    switch (name) {
    case 0x72289A28: {
        Owner_002916C0* o = m34;
        int v;
        if (o->mC->m164) v = o->m5B0->m34;
        else v = o->m5B0->m34 ^ 1;
        if (v) func_00291A78(this);
        break;
    }
    case 0xEBA11B20:
        m20 = 1;
        break;
    case 0xACAC1BAD:
        m24 = 1;
        break;
    case 0x63E93F69:
        m28 = 1;
        break;
    case 0xA6243DAA:
        return m20 != 0;
    case 0xD9DE0C65:
        func_0027C928(m34);
    case 0x65011BAA:
        func_00291A78(this);
        break;
    case 0xE0F3A644: {
        void* t = func_002A52F0(D_00392068, mC->m18);
        void* tbl = D_00392068;
        int* p = func_002A39E0(tbl, func_002B30A0(t));
        if (func_001E8708(params, 0xDE7A971B)) {
            func_002918E0(this, mC->m18, 0, *p, 1);
        } else {
            func_002918E0(this, mC->m18, m1C ^ 1, *p, 1);
        }
        break;
    }
    case 0x79EE5CCF:
        return m1C != 0;
    case 0x0B1E7291:
        func_002919B0(this);
        return 2;
    default:
        return 2;
    }
    return 1;
}
