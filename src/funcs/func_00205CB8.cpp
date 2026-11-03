extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

struct Skater_00205CB8 {
    char pad[0x164];
    bool m_is_pro;
    int m_m168;
    int m_m16C;
    char pad170[0x1B0 - 0x170];
    unsigned int m_m1B0;
    bool Matches(void* params);
};

bool Skater_00205CB8::Matches(void* params)
{
    if (func_001E8708(params, 0xD82F8AC8) && !m_m168) {
        return false;
    }
    if (func_001E8708(params, 0x5A3264BB) && m_m168) {
        return false;
    }
    if (func_001E8708(params, 0x3F813177) && !m_m16C) {
        return false;
    }
    if (func_001E8708(params, 0xE5C2F84C) && m_m16C) {
        return false;
    }
    unsigned int id;
    if (func_001E8398(params, 0xC2E3D008, &id, 0) && id != m_m1B0) {
        return false;
    }
    unsigned int type;
    if (func_001E8398(params, 0x7D02BCC3, &type, 0)) {
        unsigned int want = m_is_pro ? 0x287FCD4E : 0xB58EFC2B;
        if (type != want) {
            return false;
        }
    }
    return true;
}
