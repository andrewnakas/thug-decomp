struct Item_00143770 {
    int m0;
    unsigned char m_from[4];
    unsigned char m_to[4];
    unsigned char m_cur[4];
    int m10;
    float m_total;
    float m_left;
};

struct Game_00143770 {
    char pad[0x38];
    int m38;
};

extern void* D_0038A630;
extern void* D_00388A70;
extern Game_00143770* D_00390828;
extern "C" float func_0010FAB8();
extern "C" void func_00144508(void* list);
extern "C" Item_00143770* func_00144518(void* list, int a);
extern "C" void func_001445C8(void* list, Item_00143770* const& item);
extern "C" void func_0010A8D8(void* pool, void* p);

static inline void Remove_00143770(void* list, Item_00143770* p)
{
    func_001445C8(list, p);
}

void func_00143770()
{
    float dt = func_0010FAB8();
    if (!D_0038A630) {
        return;
    }
    func_00144508(D_0038A630);
    Item_00143770* it = func_00144518(D_0038A630, 0);
    while (it) {
        Item_00143770* dead = 0;
        if (!D_00390828->m38 || (it->m10 & 8)) {
            it->m_left -= dt;
            if (it->m_left > 0.0f) {
                float t = it->m_left / it->m_total;
                it->m_cur[0] = it->m_to[0] + (int)(((float)it->m_from[0] - (float)it->m_to[0]) * t);
                it->m_cur[1] = it->m_to[1] + (int)(((float)it->m_from[1] - (float)it->m_to[1]) * t);
                it->m_cur[2] = it->m_to[2] + (int)(((float)it->m_from[2] - (float)it->m_to[2]) * t);
                it->m_cur[3] = it->m_to[3] + (int)(((float)it->m_from[3] - (float)it->m_to[3]) * t);
            } else {
                dead = it;
            }
        }
        it = func_00144518(D_0038A630, 0);
        if (dead) {
            Remove_00143770(D_0038A630, dead);
            func_0010A8D8(D_00388A70, dead);
        }
    }
}
