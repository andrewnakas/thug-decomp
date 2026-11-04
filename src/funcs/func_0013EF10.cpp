extern void* D_0038DB38;
extern "C" void* func_001D0638(void* mgr, int id, int a);
extern "C" int func_0013F4E8(void* p);

struct Obj13EF10 {
    char m_pad[0x14C];
    int m14C;
    char m_pad150[0x1B6 - 0x150];
    short m1B6;
    int Check();
};

int Obj13EF10::Check()
{
    if (m1B6 == 1) {
        return func_0013F4E8(func_001D0638(D_0038DB38, m14C, 1));
    }
    return 0;
}
