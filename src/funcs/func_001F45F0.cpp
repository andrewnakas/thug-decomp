struct Entry_001F45F0 {
    char m_pad[0x14];
    int m_state;
    char m_pad18[0xC];
};

struct Script_001F45F0 {
    char m_pad[0x18];
    void* m_params;
};

struct Base_001F45F0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    virtual void V0_001F45F0();
    virtual void V1_001F45F0();
    virtual void V2_001F45F0();
    virtual void V3_001F45F0();
    virtual void InitFromStructure_001F45F0(void* params);
};

struct Comp_001F45F0 : Base_001F45F0 {
    Entry_001F45F0 m_entries[70];
    int m9F4;
    int m_visible;
};

extern char D_003661F0[];
extern char D_00366200[];

extern "C" void func_001F49F8(Comp_001F45F0* self);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001F0210(unsigned int script, void* params, void* a, int b, int c);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

int func_001F45F0(Comp_001F45F0* self, unsigned int msg, void* params, Script_001F45F0* script)
{
    switch (msg) {
    case 0x82CE30CE:
        self->InitFromStructure_001F45F0(params);
        break;
    case 0x57879C96:
        func_001F49F8(self);
        break;
    case 0xEE59073C:
        self->m_visible = 1;
        func_001F0210(func_001F0D78(D_003661F0), 0, 0, 0, 0);
        break;
    case 0xF1745991:
        self->m_visible = 0;
        func_001F0210(func_001F0D78(D_00366200), 0, 0, 0, 0);
        break;
    case 0x78E7D855: {
        int index;
        func_001E7DE8(params, 0, &index, 1);
        func_001E7200(script->m_params, 0x84FF9AE3, self->m_entries[index].m_state);
        break;
    }
    case 0xB341B5A5:
        for (int i = 0; i < 70; i++) {
            if (self->m_entries[i].m_state == 2) {
                self->m_entries[i].m_state = 0;
            }
        }
        break;
    case 0xB7FAC894:
        for (int i = 0; i < 70; i++) {
            if (self->m_entries[i].m_state == 3) {
                self->m_entries[i].m_state = 0;
            }
        }
        break;
    default:
        return 2;
    }
    return 1;
}
