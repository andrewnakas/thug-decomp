struct Cache_001439A8 {
    int m_timers[0x100];
    int m_400;
};

struct Game_001439A8 {
    char pad[0x38];
    int m_38;
};

extern Game_001439A8* D_00390828;
extern void* D_0038A634;
extern "C" float func_0010FAB8();
extern "C" void func_001448B0(void* list);
extern "C" Cache_001439A8* func_001448C0(void* list, int a);
extern "C" void func_0014F4B8(Cache_001439A8* c, int i);

extern "C" void func_001439A8()
{
    if (D_00390828->m_38) return;
    if (!D_0038A634) return;
    int dt = (int)(func_0010FAB8() * 1000.0f);
    func_001448B0(D_0038A634);
    Cache_001439A8* c = func_001448C0(D_0038A634, 0);
    while (c) {
        c->m_400 = -1;
        int i;
        for (i = 0; i < 0x100; i++) {
            if (c->m_timers[i] > 0) {
                c->m_timers[i] -= dt;
                if (c->m_timers[i] <= 0) {
                    c->m_timers[i] = 0;
                    func_0014F4B8(c, i);
                } else {
                    c->m_400 = i;
                }
            }
        }
        c = func_001448C0(D_0038A634, 0);
    }
}
