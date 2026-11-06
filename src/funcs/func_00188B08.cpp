extern void* D_0038C7B0;
extern "C" void func_00189CE0(void* mgr, void* sound, void* arg);

struct Entry_00188B08 {
    void* m_sound;
    unsigned int m_key;
    char pad8[0x14];
};

class Bank_00188B08 {
public:
    Entry_00188B08* m_entries;
    int m_count;

    void Update(void* arg);
};

void Bank_00188B08::Update(void* arg)
{
    Entry_00188B08* e = m_entries;
    for (int i = 0; i < m_count; i++, e++) {
        if (e->m_sound && e->m_key && e->m_key != 0xC377C572) {
            func_00189CE0(D_0038C7B0, e->m_sound, arg);
        }
    }
}
