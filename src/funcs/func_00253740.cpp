extern void* D_0038FC78;

struct Skater_00253740 {
    char pad[0x288];
    float m_val;
};

extern "C" Skater_00253740* func_0022DD38(void* self);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

bool Cmd_00253740(void* params, void* script)
{
    Skater_00253740* s = func_0022DD38(D_0038FC78);
    if (s) {
        float v;
        func_001E7EB0(params, 0, &v, 1);
        s->m_val = v;
        return true;
    }
    return false;
}
