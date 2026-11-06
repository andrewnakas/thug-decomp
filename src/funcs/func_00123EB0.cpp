class Obj_00123EB0 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x80 - 0x10];
    float m80;
    char pad84[0xD0 - 0x84];
    float mD0;
    void SetValue(float v, int both);
};

void Obj_00123EB0::SetValue(float v, int both)
{
    if (mD0 != v) {
        mD0 = v;
        m_flags |= 0x400;
    }
    if (both && m80 != v) {
        m80 = v;
        m_flags |= 0x400;
    }
}
