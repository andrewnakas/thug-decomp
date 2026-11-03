struct Info_001DBCB0 {
    const char* m_name;
    unsigned int m_crc;
    float m_x;
    float m_y;
    float m_scale;
    float m_rot;
    float m_alpha;
    float m_z;
};

extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" int func_00331BB8(const char* s);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

bool func_001DBCB0(void* params, Info_001DBCB0* info)
{
    info->m_name = 0;
    info->m_crc = 0;
    info->m_x = 100.0f;
    info->m_y = 100.0f;
    info->m_scale = 100.0f;
    info->m_rot = 0.0f;
    info->m_alpha = 100.0f;
    info->m_z = 100.0f;
    func_001E7C80(params, 0x07713C7B, &info->m_name, 0);
    if (!info->m_name) {
        return false;
    }
    const char* base = info->m_name;
    int len = func_00331BB8(info->m_name);
    for (int i = 0; i < len; i++) {
        if (info->m_name[i] == '\\' || info->m_name[i] == '/') {
            base = &info->m_name[i + 1];
        }
    }
    info->m_crc = func_001F0D78(base);
    func_001E7EB0(params, 0xFA3E14C5, &info->m_x, 0);
    func_001E7EB0(params, 0x1C5EBB24, &info->m_y, 0);
    func_001E7EB0(params, 0x0693DAAF, &info->m_scale, 0);
    func_001E7EB0(params, 0x4391992D, &info->m_rot, 0);
    func_001E7EB0(params, 0xF573682F, &info->m_alpha, 0);
    func_001E7EB0(params, 0x312CCBCF, &info->m_z, 0);
    return true;
}
