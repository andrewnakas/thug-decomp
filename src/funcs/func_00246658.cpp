extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

struct Goal_00246658 {
    char pad0[0x20];
    void* m_params;

    bool SetScore(int score);
};

bool Goal_00246658::SetScore(int score)
{
    int best = 0;
    func_001E7DE8(m_params, 0x78FFB85C, &best, 0);
    func_001E7200(m_params, 0x819FC1D1, score);
    if (best < score) {
        func_001E7200(m_params, 0x78FFB85C, score);
        return true;
    }
    return false;
}
