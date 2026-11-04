extern "C" float func_0010FAB8();
extern "C" void* func_001E5548(unsigned int crc, int a);
extern "C" int func_001E7EB0(void* s, unsigned int crc, float* out, int req);

struct Obj_001C5920 {
    char pad0[0x1C];
    int m_1C;
    char pad20[0xC4 - 0x20];
    float m_C4;
    void Update();
};

void Obj_001C5920::Update()
{
    if (m_1C != 2 && m_1C != 4) {
        float dt = func_0010FAB8();
        float k;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0xB32C972B, &k, 1);
        m_C4 = m_C4 + -m_C4 * (dt * k);
    }
}
