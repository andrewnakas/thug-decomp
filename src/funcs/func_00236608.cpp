struct Trick_00236608 {
    int m_score;
    unsigned int m_name;
    unsigned int m_category;
    int mC;
    int m10;
    int m_switch;
    unsigned int m_flags;
};

struct Score_00236608 {
    char m_pad[0x44];
    char m_log[4];
};

extern "C" Trick_00236608* func_0023AFE8(void* log, int index);
extern "C" int func_002388C0(Score_00236608* self, unsigned int category);
extern "C" int func_002388F0(Score_00236608* self, unsigned int name);

int func_00236608(Score_00236608* self, int start, int end)
{
    int total = 0;
    int mult = 2;
    for (int i = start; i < end; i++) {
        if (func_0023AFE8(self->m_log, i)->m_flags & 2) {
            mult = 2;
        } else if (i == 0 || (func_0023AFE8(self->m_log, i - 1)->m_flags & 2)) {
            mult = func_002388C0(self, func_0023AFE8(self->m_log, i)->m_category);
        }
        int score = func_002388F0(self, func_0023AFE8(self->m_log, i)->m_name);
        score = func_0023AFE8(self->m_log, i)->m_score * score * mult / 200;
        if (func_0023AFE8(self->m_log, i)->m_switch) {
            score = score * 120 / 100;
        }
        total += score;
    }
    return total;
}
