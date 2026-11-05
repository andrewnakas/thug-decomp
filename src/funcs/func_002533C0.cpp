extern void* D_0038FC78;

struct Skater_002533C0 {
    char pad[0x280];
    int m_flag;
};

extern "C" Skater_002533C0* func_0022DD38(void* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Cmd_002533C0(void* params, void* script)
{
    Skater_002533C0* s = func_0022DD38(D_0038FC78);
    if (s) {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        if (!v) s->m_flag = 0;
        else s->m_flag = 1;
        return true;
    }
    return false;
}
