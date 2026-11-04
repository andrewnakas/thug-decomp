struct Array_002401F8 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Goal_002401F8 {
    char m_pad[0x68];
    int m_level;
    int m_group;
};

extern "C" Array_002401F8* func_001E55B8(unsigned int name, int assert_);
extern "C" Array_002401F8* func_001E93A0(Array_002401F8* self, int index);
extern "C" void* func_001E9378(Array_002401F8* self, int index);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" Goal_002401F8* func_0023BAD8(void* self, unsigned int id, int flag);

void func_002401F8(void* self)
{
    Array_002401F8* levels = func_001E55B8(0xB892776F, 1);
    int num_levels = levels->m_size;
    for (int i = 0; i < num_levels; i++) {
        Array_002401F8* level = func_001E93A0(levels, i);
        int num_groups = level->m_size;
        for (int j = 0; j < num_groups; j++) {
            Array_002401F8* group = func_001E93A0(level, j);
            int num = group->m_size;
            for (int k = 0; k < num; k++) {
                unsigned int id;
                if (func_001E8398(func_001E9378(group, k), 0x9982E501, &id, 0)) {
                    Goal_002401F8* goal = func_0023BAD8(self, id, 0);
                    if (goal) {
                        goal->m_level = i;
                        goal->m_group = j;
                    }
                }
            }
        }
    }
}
