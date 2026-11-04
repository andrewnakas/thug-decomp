struct Entry_00237A30 {
    int m_score;
    char pad4[0x14];
    int m_flags;
    char m_active;
};

struct Thing_00237A30 {
    char pad[0x20];
    int m_20;
};

extern int D_0038FC78;
extern "C" Entry_00237A30* func_0023AFE8(void* list, int index);
extern "C" void* func_0022DF08(int mgr, int id);
extern "C" Thing_00237A30* func_00185578(void* obj, unsigned int name);
extern "C" void func_00238480(void* self);
extern "C" void func_00238780(void* self, int a);
extern "C" void func_00238EF8(void* self, int a, int b);

struct Obj_00237A30 {
    short m_0;
    short m_id;
    int m_4;
    int m_8;
    int m_C;
    char pad10[0x34];
    char m_list[0x14];
    int m_count;
    int m_5C;

    void AddScore(int points);
};

void Obj_00237A30::AddScore(int points)
{
    if (m_count > 0) {
        if (func_0023AFE8(m_list, m_count - 1)->m_active) {
            int n = 0;
            int i;
            for (i = m_count - 1; i > 0; i--) {
                if (func_0023AFE8(m_list, i)->m_flags & 2) {
                    break;
                }
                n++;
            }
            if (n < 11) {
                if ((func_0023AFE8(m_list, m_count - 1)->m_flags & 2) || func_0023AFE8(m_list, m_count - 1)->m_score < 20001) {
                    Thing_00237A30* t = func_00185578(func_0022DF08(D_0038FC78, m_id), 0x9F9CC949);
                    if (!t || !t->m_20) {
                        func_0023AFE8(m_list, m_count - 1)->m_score += points;
                        func_00238480(this);
                        func_00238780(this, 0);
                        m_8 = 0;
                        func_00238EF8(this, m_C, m_5C);
                    }
                }
            }
        }
    }
}
