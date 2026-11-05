extern void* D_0038FC78;

struct Skater_002538B0 {
    char pad[0x28C];
    int m_val;
};

extern "C" Skater_002538B0* func_0022DD38(void* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Cmd_002538B0(void* params, void* script)
{
    Skater_002538B0* s = func_0022DD38(D_0038FC78);
    if (s) {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        s->m_val = v;
        return true;
    }
    return false;
}
