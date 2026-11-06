/* sym: _$_14Sound_00187EE0 = 0x001E6AE8 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Sound_00187EE0 {
public:
    ~Sound_00187EE0();
};

struct Entry_00187EE0 {
    char pad0[0x18];
    Sound_00187EE0* m_sound;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

class Bank_00187EE0 {
public:
    Entry_00187EE0* m_entries;
    int m_count;

    ~Bank_00187EE0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Bank_00187EE0::~Bank_00187EE0()
{
    if (m_entries) {
        for (int i = 0; i < m_count; i++) {
            delete m_entries[i].m_sound;
        }
        delete[] m_entries;
    }
}
