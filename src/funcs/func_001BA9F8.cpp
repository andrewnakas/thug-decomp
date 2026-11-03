struct Slot_001BA9F8 {
    int m_active;
    unsigned int m_start;
    unsigned int m_duration;
};

struct Obj_001BA9F8 {
    char pad[0x104];
    unsigned int m_flags;
};

struct Game_001BA9F8 {
    char pad[0x38];
    int m38;
};

extern Game_001BA9F8* D_00390828;
extern char D_0038D428[];
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" void func_00107FB0(int id);
extern "C" void func_00107CA0(int id, int slot, int value);
extern "C" unsigned int func_0033EBE0(float f);
extern "C" unsigned int func_0010FC30();

struct C_001BA9F8 {
    char pad[0xC];
    Obj_001BA9F8* mC;
    char pad10[0xC];
    int m1C;
    Slot_001BA9F8 m_slots[2];
    int m38;
    int Call(unsigned int name, void* params);
};

int C_001BA9F8::Call(unsigned int name, void* params)
{
    switch (name) {
    case 0xDF8A5F0A:
        if (!func_001E8708(params, 0xD443A2BC)) {
            if (D_00390828->m38)
                return 1;
            if (mC->m_flags & 1)
                return 1;
        }
        if (m1C) {
            int slot = 0;
            func_001E7DE8(params, 0x114FC131, &slot, 0);
            float value = 0.0f;
            func_001E7EB0(params, 0x9E497FC6, &value, 0);
            if (func_001E87B8(params, D_0038D428)) {
                func_00107FB0(m38);
                for (int i = 1; i != -1; i--)
                    m_slots[i].m_active = 0;
            } else {
                func_00107CA0(m38, slot, (int)value);
            }
            float time = 0.0f;
            if (func_001E7EB0(params, 0x79A07F3F, &time, 0)) {
                m_slots[slot].m_active = 1;
                m_slots[slot].m_duration = (unsigned int)(time * 1000.0f);
                m_slots[slot].m_start = func_0010FC30();
            } else {
                m_slots[slot].m_active = 0;
            }
        }
        break;
    default:
        return 2;
    }
    return 1;
}
