struct Setting_00205428 {
    int m0;
    bool m_value;
    int m_stamp;
};

struct Model_00205428 {
    char pad[0x30];
    Setting_00205428 m_setting;
};

struct Engine_00205428 {
    char pad[0x5B0];
    Model_00205428* m_model;
};

struct Profile_00205428 {
    char pad[0x5C];
    char m_info[4];
};

extern "C" unsigned int func_00262248(Profile_00205428* p, unsigned int name);
extern "C" int func_002623B8(Profile_00205428* p);
extern "C" const char* func_002624F0(Profile_00205428* p);
extern "C" int func_00262388(Profile_00205428* p);
extern "C" void* func_00104110(void* str, const char* s);
extern "C" bool func_001E7DE8(void* s, unsigned int name, int* out, int required);
extern "C" bool func_001E8870(void* s, unsigned int name, const char** out, int required);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_0010FC30();
extern "C" void* func_00185578(void* self, unsigned int name);
extern "C" void func_00291AD8(void* p);

static inline void SetValue_00205428(Model_00205428* m, bool value)
{
    Setting_00205428* s = &m->m_setting;
    if (s->m_value != value) {
        s->m_value = value;
        s->m_stamp = func_0010FC30();
    }
}

struct Skater_00205428 {
    char pad[0x160];
    unsigned int m_board;
    bool m_is_pro;
    int m_m168;
    int m_m16C;
    char m_name[0x1B0 - 0x170];
    int m_m1B0;
    char m_str[0x2E0 - 0x1B4];
    Engine_00205428* m_engine;
    char pad2E4[0x31C - 0x2E4];
    int m_local;
    void Apply(Profile_00205428* profile);
};

void Skater_00205428::Apply(Profile_00205428* profile)
{
    m_board = func_00262248(profile, 0xC15DBF86);
    m_is_pro = func_00262248(profile, 0x7D02BCC3) == 0x287FCD4E;
    m_m168 = func_002623B8(profile);
    func_00104110(m_str, func_002624F0(profile));
    func_001E7DE8(profile->m_info, 0x3F813177, &m_m16C, 1);
    const char* name;
    func_001E8870(profile->m_info, 0x562E3ECD, &name, 1);
    func_00331A9C(m_name, name);
    m_m1B0 = func_00262388(profile);
    if (m_local) {
        SetValue_00205428(m_engine->m_model, !m_is_pro);
        func_00291AD8(func_00185578(this, 0x488AF07A));
    }
}
