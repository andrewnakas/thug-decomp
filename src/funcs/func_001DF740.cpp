struct Entry_001DF740 {
    int m0;
    int m_id;
    float m_volume;
    float m_pitch;
    char m_pad[0x28 - 0x10];
};

extern Entry_001DF740 D_003EE8E0[];
extern int D_0038E128;

extern "C" bool func_001DED40();
extern "C" void func_001DED60(int id);
extern "C" int func_001DF1C8(int id, int a, float f, int b, int owner, int flags);

extern "C" int func_001DF740(int id, int a, int b, int owner, float f)
{
    if (func_001DED40())
        return 0;
    if (!owner)
        owner = id;
    func_001DED60(owner);
    int index = func_001DF1C8(id, a, f, b, owner, 0);
    if (index != -1) {
        D_0038E128 = index;
        D_003EE8E0[index].m_pitch = 1020.0f;
        D_003EE8E0[index].m_volume = 100.0f;
        return D_003EE8E0[index].m_id;
    }
    return 0;
}
