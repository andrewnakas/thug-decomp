extern "C" void* func_001E9378(void* scr, int arg);

struct Script_001AF480 {
    int m_pad[3];
    int m_count;
};

extern "C" Script_001AF480* func_001E55B8(int id, int flags);

struct C_001AF480 {
    int m_pad[4];
    unsigned int Match(int id, const char* name);
};

extern "C" int func_001AF390(C_001AF480* self, void* p, const char* name);

unsigned int C_001AF480::Match(int id, const char* name)
{
    unsigned int mask = 0;
    Script_001AF480* scr = func_001E55B8(id, 0);
    int n = scr->m_count;
    for (int i = 0; i < n; i++) {
        if (func_001AF390(this, func_001E9378(scr, i), name)) mask |= 1 << i;
    }
    return mask;
}
