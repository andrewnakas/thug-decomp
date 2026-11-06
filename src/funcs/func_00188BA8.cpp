extern void* D_0038C7B0;
extern "C" void func_00189D80(void* mgr, void* sound, void* arg);

struct Entry_00188BA8 {
    void* m_sound;
    char pad4[0x18];
};

class Bank_00188BA8 {
public:
    Entry_00188BA8* m_entries;
    int m_count;

    void Apply(void* arg);
};

void Bank_00188BA8::Apply(void* arg)
{
    Entry_00188BA8* e = m_entries;
    for (int i = 0; i < m_count; i++, e++) {
        if (e->m_sound) {
            func_00189D80(D_0038C7B0, e->m_sound, arg);
        }
    }
}
