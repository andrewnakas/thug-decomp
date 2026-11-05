extern "C" int func_0010FC30();

struct Timer_0027C640 {
    int m0;
    int m_on;
    int m_time;
    void Set(int on)
    {
        if (m_on != on) {
            m_on = on;
            m_time = func_0010FC30();
        }
    }
};

struct Group_0027C640 {
    Timer_0027C640 m_timers[23];
};

struct Data_0027C640 {
    char pad[0x24];
    Group_0027C640 m_group;
};

struct Flag_0027C640 {
    char pad[0x28];
    int m28;
};

struct Obj_0027C640 {
    char pad[0x59C];
    Flag_0027C640* m59C;
    char pad2[0x5B0 - 0x5A0];
    Data_0027C640* m5B0;
    void SetState(int i, int on)
    {
        m5B0->m_group.m_timers[i].Set(on);
        if (i == 7)
            m59C->m28 = on;
    }
    void Pulse();
};

void Obj_0027C640::Pulse()
{
    for (int i = 0x16; i != -1; i--) {
        if (i == 1)
            continue;
        SetState(i, 1);
        SetState(i, 0);
    }
}
