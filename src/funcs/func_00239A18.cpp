struct Entry_00239A18 {
    int m0;
    int m4;
    int m_level;
    int m_angle;
    unsigned int m_name;
    int m14;
    unsigned int m_flags;
};

struct Self_00239A18 {
    char m_pad[0x44];
    char m_list[0x14];
    int m_count;
};

extern "C" Entry_00239A18* func_0023AFE8(void* list, int index);
extern "C" int abs(int);
extern "C" int func_001E53A0(unsigned int name, int a);

static inline bool IsNamed_00239A18(Entry_00239A18* entry, const unsigned int& name)
{
    return entry->m_name == name;
}


int func_00239A18(Self_00239A18* self, unsigned int name, int level, int check_angle)
{
    int count = 0;
    int current = 1;
    for (int i = 0; i < self->m_count; i++) {
        if (func_0023AFE8(self->m_list, i)->m_flags & 2) {
            current = 1;
        } else if (i == 0 || (i > 0 && (func_0023AFE8(self->m_list, i - 1)->m_flags & 2))) {
            current = func_0023AFE8(self->m_list, i)->m_level;
        }
        if (IsNamed_00239A18(func_0023AFE8(self->m_list, i), name)) {
            if (!level) {
                count++;
            } else if (level == current) {
                if (!check_angle) {
                    count++;
                } else {
                    int diff = abs(abs(func_0023AFE8(self->m_list, i)->m_angle) - level * 180);
                    count += diff < func_001E53A0(0xFCFACAB8, 0);
                }
            }
        }
    }
    return count;
}
