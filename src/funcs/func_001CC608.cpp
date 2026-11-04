extern float D_00387B40;
extern float D_00387B44;

extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);
extern "C" float func_00340F60(float a);

static inline float Abs_001CC608(float x)
{
    return (x < 0.0f) ? -x : x;
}

struct Board_001CC608 {
    char pad0[0x290];
    float m_290;
};

struct Skater_001CC608 {
    char pad0[0x90];
    unsigned int m_state;
    char pad94[0x8C0];
    int m_954;
    char pad958[0xD0];
    Board_001CC608* m_board;

    void CheckBail();
};

extern "C" void func_001CC6B0(Skater_001CC608* self);

void Skater_001CC608::CheckBail()
{
    float d = Abs_001CC608(D_00387B40 - Abs_001CC608(m_board->m_290));
    float angle;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x7EE1B95B, &angle, 1);
    if (func_00340F60(angle * D_00387B44) < d) {
        func_001CC6B0(this);
    } else {
        m_954 = 0;
        m_state = 0xC84243DA;
    }
}
