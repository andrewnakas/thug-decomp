struct Ent_001A2828 {
    int m_0; int m_on0; char pad0[0x28]; float m_vel0[4]; float m_pos0[4];
    int m_on1; char pad1[0x2C]; float m_vel1[4]; float m_pos1[4];
    int m_on2; char pad2[0x2C]; float m_vel2[4]; float m_pos2[4];
    char pad3[0x0];
};
static inline void Scroll_001A2828(const float* vel, float* pos)
{
    pos[0] = (float)((int)(pos[0] + vel[0]) & 0xFFF);
    pos[1] = (float)((int)(pos[1] + vel[1]) & 0xFFF);
    pos[2] = (float)((int)(pos[2] + vel[2]) & 0xFFF);
    pos[3] = pos[3] + vel[3];
}
extern "C" int func_001A2CD0(void* self);
extern "C" Ent_001A2828* func_001A2CD8(void* self);
struct Obj_001A2828 { void Update(); };
void Obj_001A2828::Update()
{
    int n = func_001A2CD0(this);
    Ent_001A2828* e = func_001A2CD8(this);
    for (int i = 0; i < n; i++, e++) {
        if (e->m_on0) Scroll_001A2828(e->m_vel0, e->m_pos0);
        if (e->m_on1) Scroll_001A2828(e->m_vel1, e->m_pos1);
        if (e->m_on2) Scroll_001A2828(e->m_vel2, e->m_pos2);
    }
}
