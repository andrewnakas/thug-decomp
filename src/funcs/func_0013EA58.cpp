extern "C" short func_0013E9D8(void* self);
extern "C" void* func_0013E9B8(void* self, int i);
extern "C" int func_00132170(void* p);
extern "C" int func_00132418(void* p);

class C_0013EA58 {
public:
    char m_pad0[0x104];
    void* m_others[43];
    short m_flags;
    short m_count;
    short m_otherCount;
    short m_keyCount;
    void Clear();
};

void C_0013EA58::Clear()
{
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        func_00132170(func_0013E9B8(this, i));
    }
    m_count = 0;
    for (short j = 0; j < m_otherCount; j++) {
        func_00132418(m_others[j]);
    }
    m_otherCount = 0;
    m_keyCount = 0;
}
