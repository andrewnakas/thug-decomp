extern void* D_0038FC78;

struct Skater_002537F8 {
    char pad[0x290];
    int m_val;
};

extern "C" Skater_002537F8* func_0022DD38(void* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Cmd_002537F8(void* params, void* script)
{
    Skater_002537F8* s = func_0022DD38(D_0038FC78);
    if (s) {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        s->m_val = v;
        return true;
    }
    return false;
}
