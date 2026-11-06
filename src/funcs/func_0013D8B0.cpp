class Obj_0013D8B0 {
public:
    int m0;
    int m_value;
    char pad8[0x1B8 - 0x8];
    virtual void V0();
    virtual void V1();
    virtual int Refresh();
    int SetValue(int v);
};

int Obj_0013D8B0::SetValue(int v)
{
    int r = 0;
    if (v != m_value) {
        r = Refresh();
        if (r) {
            m_value = v;
        }
    }
    return r;
}
