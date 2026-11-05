extern void* D_0038FC78;

struct Skater_00253660 {
    char pad[0x27C];
    int m_flag;
};

extern "C" Skater_00253660* func_0022DD38(void* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Cmd_00253660(void* params, void* script)
{
    Skater_00253660* s = func_0022DD38(D_0038FC78);
    if (s) {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        if (!v) s->m_flag = 0;
        else s->m_flag = 1;
        return true;
    }
    return false;
}
