struct Data_00135438 {
    int m0;
    unsigned short m_flags;
};

extern "C" void func_001D66D8(Data_00135438* d);

class Obj_00135438 {
public:
    char pad0[0x24];
    Data_00135438* m_data;
    void SetActive(int on);
};

void Obj_00135438::SetActive(int on)
{
    Data_00135438* d = m_data;
    if (d) {
        if (!on) {
            d->m_flags &= ~0x80;
        } else if (!(d->m_flags & 0x80)) {
            d->m_flags |= 0x80;
            func_001D66D8(m_data);
        }
    }
}
