struct Goal_0024B640 {
    char pad0[0x50];
    int m_win_record;
    char pad54[0xA8 - 0x54];
    int m_gold;
    int m_silver;
    int m_bronze;
    int m_reward_given;
    void GetInfo(void* s);
};

extern "C" void func_002476C0(Goal_0024B640* g, void* s);
extern "C" void func_001E7268(void* s, char* name, int value);
extern "C" void func_001E73C8(void* s, char* name, int value);

extern char D_00374098[];
extern char D_003740A8[];
extern char D_00390210[];
extern char D_00374068[];
extern char D_003740B8[];

void Goal_0024B640::GetInfo(void* s)
{
    func_002476C0(this, s);
    if (m_bronze) {
        func_001E7268(s, D_00374098, 1);
    } else {
        func_001E7268(s, D_00374098, 0);
    }
    if (m_silver) {
        func_001E73C8(s, D_003740A8, 1);
    } else {
        func_001E73C8(s, D_003740A8, 0);
    }
    if (m_gold) {
        func_001E73C8(s, D_00390210, 1);
    } else {
        func_001E73C8(s, D_00390210, 0);
    }
    func_001E7268(s, D_00374068, m_win_record);
    func_001E7268(s, D_003740B8, m_reward_given);
}
