class Stats_00206D58 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Reset(int a);
};

extern "C" bool func_001E8248(void* params, unsigned int name, void** out, int required);
extern "C" int func_001E9270(void* a, int i);
extern "C" void func_001F5008(Stats_00206D58* s, int i, int value);

struct Obj_00206D58 {
    char pad0[0x2EC];
    Stats_00206D58* m_stats;

    void ReadArray(void* params);
};

void Obj_00206D58::ReadArray(void* params)
{
    m_stats->Reset(0);
    void* a = 0;
    func_001E8248(params, 0x44B66A9F, &a, 0);
    for (int i = 0; i < 0x46; i++)
        func_001F5008(m_stats, i, func_001E9270(a, i));
}
