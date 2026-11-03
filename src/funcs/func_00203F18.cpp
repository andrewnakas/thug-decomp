struct Comp_00203F18 {
    char pad[0x1C];
    int m_paused;
};

extern void* D_00390828;
extern char D_00366D68[];
extern char D_00366D78[];

extern "C" Comp_00203F18* func_00185578(void* self, unsigned int name);
extern "C" bool func_00203300(unsigned int name, int a);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00253F60(void* p, int pause);
extern "C" void func_00273250(Comp_00203F18* c, int a);

struct Skater_00203F18 {
    char pad[0x324];
    int m_pause_state;
    void SetPauseState(int state);
};

void Skater_00203F18::SetPauseState(int state)
{
    void* mgr = D_00390828;
    if (m_pause_state == state || !func_00185578(this, 0xD9151D4D)) {
        return;
    }
    m_pause_state = state;
    switch (state) {
    case 0:
        if (func_00203300(0x9816E1E3, 0)) {
            func_00103F28(D_00366D68);
            func_00253F60(mgr, 0);
        }
        break;
    case 1:
        if (func_00203300(0x9816E1E3, 0)) {
            func_00103F28(D_00366D78);
            func_00253F60(mgr, 1);
        } else {
            Comp_00203F18* c = func_00185578(this, 0xD9151D4D);
            if (c->m_paused != state) {
                func_00273250(c, 1);
            }
        }
        break;
    case 2:
        if (!func_00203300(0x9816E1E3, 0)) {
            Comp_00203F18* c = func_00185578(this, 0xD9151D4D);
            if (c->m_paused) {
                func_00273250(c, 0);
            }
        }
        break;
    }
}
