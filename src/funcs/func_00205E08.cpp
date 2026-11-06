struct Script_00205E08 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern "C" bool func_001E8398(void* s, unsigned int name, int* out, int required);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_0022C4A0(void* game, void* skater, int a);

struct Skater_00205E08 {
    char pad[0x1B0];
    int m_m1B0;
    char pad1B4[0x31C - 0x1B4];
    bool m_local;
    int m_id;
    char pad324[0x388 - 0x324];
    int m_m388;
    bool Dispatch(unsigned int name, void* params, Script_00205E08* script);
};

extern "C" void func_00203DF0(Skater_00205E08* self);
extern "C" bool func_00205F70(Skater_00205E08* self, unsigned int name, void* params, Script_00205E08* script);

bool Skater_00205E08::Dispatch(unsigned int name, void* params, Script_00205E08* script)
{
    switch (name) {
    case 0x7015BC33:
        return m_local;
    case 0xBF450BAB:
        func_00203DF0(this);
        break;
    case 0x1C5612EE: {
        int value;
        func_001E8398(params, 0, &value, 1);
        return value == m_m1B0;
    }
    case 0x97C8285A:
        func_001E7360(script->m_params, 0x7A039889, m_id == 1 ? 0xE17B231A : 0x967C138C);
        break;
    case 0xBCE85494:
        func_0022C4A0(D_0038FC78, this, 1);
        break;
    case 0x0C09C1B7:
        func_0022C4A0(D_0038FC78, this, 0);
        break;
    case 0x72AECFC0:
        m_m388 = 0;
        break;
    default:
        return func_00205F70(this, name, params, script);
    }
    return true;
}
