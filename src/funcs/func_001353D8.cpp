struct Data_001353D8 {
    int m0;
    unsigned short m_flags;
};

class Obj_001353D8 {
public:
    int m0;
    unsigned int m_flags;
    char pad8[0x24 - 0x8];
    Data_001353D8* m_data;
    void SetHidden(int on);
};

void Obj_001353D8::SetHidden(int on)
{
    if (on) {
        m_flags |= 1;
    } else {
        m_flags &= ~1;
    }
    if (m_data) {
        if (on) {
            m_data->m_flags &= ~2;
        } else {
            m_data->m_flags |= 2;
        }
    }
}
