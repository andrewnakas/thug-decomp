struct Data_00135380 {
    int m0;
    int m4;
    void* m_anim;
};

extern "C" void func_001D8B68(void* anim);

class Obj_00135380 {
public:
    int m0;
    unsigned int m_flags;
    char pad8[0x24 - 0x8];
    Data_00135380* m_data;
    void Reset();
};

void Obj_00135380::Reset()
{
    if (m_data && m_data->m_anim) {
        func_001D8B68(m_data->m_anim);
        if (m_flags & 0x40) {
            m_flags |= 0x20;
        }
    }
}
