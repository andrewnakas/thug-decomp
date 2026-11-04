extern "C" bool func_001E8618(void* params, unsigned int id);
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);

struct Wheel_00196340 {
    char pad0[0xD0];
    int m_type;
    int m_side;
    char padD8[0xDC - 0xD8];
    float mDC;
    float mE0;
    float mE4;
    float mE8;
    float mEC;
    float mF0;
    float mF4;
    float mF8;
    float mFC;
    float m100;
    float m104;
    float m108;
    char pad10C[0x110 - 0x10C];
    float m110;
    float m114;
};

struct Obj_00196340 {
    void LoadWheel(Wheel_00196340* w, void* params);
};

void Obj_00196340::LoadWheel(Wheel_00196340* w, void* params)
{
    unsigned int cs;
    if (func_001E8618(params, 0x07560E63)) {
        func_001E8398(params, 0x07560E63, &cs, 0);
        switch (cs) {
        case 0x85981897:
            w->m_type = 1;
            break;
        case 0x4B358AEB:
            w->m_type = 2;
            break;
        case 0x613631CD:
            w->m_type = 0;
            break;
        }
    }
    if (func_001E8618(params, 0x97E20A70)) {
        func_001E8398(params, 0x97E20A70, &cs, 0);
        switch (cs) {
        case 0x9855D7E0:
            w->m_side = 0;
            break;
        case 0x8A18CA56:
            w->m_side = 1;
            break;
        }
    }
    func_001E7EB0(params, 0x9E931FDF, &w->mE8, 0);
    func_001E7EB0(params, 0xAFA960FF, &w->mEC, 0);
    func_001E7EB0(params, 0xC48391A5, &w->mE0, 0);
    if (func_001E8618(params, 0xCA73775D)) {
        func_001E7EB0(params, 0xCA73775D, &w->mE4, 0);
        w->mE4 = 386.4f / w->mE4;
    }
    func_001E7EB0(params, 0xD87D0183, &w->mDC, 0);
    func_001E7EB0(params, 0xF36B97C8, &w->mFC, 0);
    func_001E7EB0(params, 0x674852F6, &w->m100, 0);
    func_001E7EB0(params, 0x52242919, &w->m104, 0);
    func_001E7EB0(params, 0x6D615F67, &w->m108, 0);
    if (func_001E8618(params, 0x60B2C097)) {
        func_001E7EB0(params, 0x60B2C097, &w->mF0, 0);
        w->mF0 *= 17.6f;
    }
    if (func_001E8618(params, 0xBB0D9370)) {
        func_001E7EB0(params, 0xBB0D9370, &w->mF4, 0);
        w->mF4 *= 17.6f;
    }
    if (func_001E8618(params, 0xB71803AD)) {
        func_001E7EB0(params, 0xB71803AD, &w->mF8, 0);
        w->mF8 *= 17.6f;
    }
    if (func_001E8618(params, 0x3BCCBADC)) {
        func_001E7EB0(params, 0x3BCCBADC, &w->m110, 0);
        w->m110 *= 12.0f;
    }
    if (func_001E8618(params, 0x9439D144)) {
        func_001E7EB0(params, 0x9439D144, &w->m114, 0);
        w->m114 *= 12.0f;
    }
}
