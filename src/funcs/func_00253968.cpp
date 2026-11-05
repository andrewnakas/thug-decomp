extern void* D_0038FC78;

struct Skater_00253968 {
    char pad[0x294];
    int m_val;
};

extern "C" Skater_00253968* func_0022DD38(void* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Cmd_00253968(void* params, void* script)
{
    Skater_00253968* s = func_0022DD38(D_0038FC78);
    if (s) {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        s->m_val = v;
        return true;
    }
    return false;
}
