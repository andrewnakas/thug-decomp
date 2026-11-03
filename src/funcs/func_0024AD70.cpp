extern char D_00373F28[];
extern char D_00373F38[];
extern char D_00373F48[];

struct Goal_0024AD70 {
    char pad[0xAC];
    unsigned int m_parent;
    int padB0;
    int m_level;
};

extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* mgr, unsigned int name, int a);
extern "C" void* func_00244528(void* goal);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);

void* func_0024AD70(Goal_0024AD70* goal)
{
    void* result = 0;
    if (goal->m_parent) {
        void* params = func_00244528(func_0023BAD8(func_00240850(), goal->m_parent, 1));
        switch (goal->m_level) {
        case 1:
            func_001E81F0(params, D_00373F28, &result, 0);
            break;
        case 2:
            func_001E81F0(params, D_00373F38, &result, 0);
            break;
        case 3:
            func_001E81F0(params, D_00373F48, &result, 0);
            break;
        }
    }
    return result;
}
