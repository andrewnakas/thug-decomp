/* sym: _$_12Sub_00129118 = 0x0011D730 */
extern "C" void func_00132120(void* p);

struct Sub_00129118 {
    int m0;
    ~Sub_00129118();
};

struct Quat_00129118 {
    float x, y, z, w;
    void Identity()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
};

struct Slot_00129118 {
    void* m_ref;
    Sub_00129118* m_sub;
    int m8;
    int mC;
    Quat_00129118 m_rot;
};

struct Obj_00129118 {
    char pad[0x1A0];
    Slot_00129118 m_slots[25];
    int m_count;
    void Clear();
};

void Obj_00129118::Clear()
{
    for (int i = 0; i < 25; i++) {
        Slot_00129118* s = &m_slots[i];
        if (s->m_ref) {
            func_00132120(s->m_ref);
            s->m_ref = 0;
        }
        delete s->m_sub;
        s->m_rot.Identity();
    }
    m_count = 0;
}
