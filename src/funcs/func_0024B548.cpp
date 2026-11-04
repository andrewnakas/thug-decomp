extern char D_00374098[];
extern char D_003740A8[];
extern char D_00390210[];
extern char D_003740B8[];
extern char D_00374068[];

struct Goal_0024B548 {
    char pad[0x50];
    int m_record;
    char pad54[0xB0 - 0x54];
    int m_beaten;
    int m_rewardGiven;
};

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_002474E8(Goal_0024B548* goal, void* params);

void func_0024B548(Goal_0024B548* goal, void* params)
{
    int bronze;
    func_001E7E58(params, D_00374098, &bronze, 0);
    if (bronze)
        goal->m_beaten = 1;
    int silver;
    func_001E7E58(params, D_003740A8, &silver, 0);
    if (silver)
        goal->m_beaten = 1;
    int gold;
    func_001E7E58(params, D_00390210, &gold, 0);
    if (gold)
        goal->m_beaten = 1;
    int given;
    func_001E7E58(params, D_003740B8, &given, 0);
    goal->m_rewardGiven = given;
    int record;
    if (func_001E7E58(params, D_00374068, &record, 0))
        goal->m_record = record;
    func_002474E8(goal, params);
}
