extern "C" float func_0010FAB8();
extern "C" void* func_00185578(void* obj, unsigned int crc);
extern "C" void* func_001E5548(unsigned int crc, int a);
extern "C" int func_001E7EB0(void* s, unsigned int crc, float* out, int req);

struct Info_001C6540 {
    char pad0[0xC];
    int m_C;
    char pad10[0x5C - 0x10];
    int m_5C;
};

struct Comp_001C6540 {
    char pad0[0x1C];
    Info_001C6540* m_1C;
};

struct Obj_001C6540 {
    char pad0[0xC];
    void* m_C;
    char pad10[0xB54 - 0x10];
    float m_B54;
    void Update();
};

void Obj_001C6540::Update()
{
    Info_001C6540* info = ((Comp_001C6540*)func_00185578(m_C, 0xD262802F))->m_1C;
    if (info->m_C * info->m_5C > 0) {
        m_B54 = 1.0f;
    } else {
        float rate;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x3FB31DFC, &rate, 1);
        float r = rate;
        r *= func_0010FAB8();
        float v = m_B54 - r;
        if (v < 0.0f) {
            v = 0.0f;
        }
        m_B54 = v;
    }
}
