extern "C" short func_0013E9D8(void* self);

class C_0013EB18 {
public:
    char m_pad0[0xA0];
    int m_keys[18];
    int m_mask;
    bool SetHidden(int key, bool hidden);
};

bool C_0013EB18::SetHidden(int key, bool hidden)
{
    bool any = (key == (int)0xC4E78E22);
    bool done = false;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        if (key == m_keys[i] || any) {
            if (hidden) {
                m_mask &= ~(1 << i);
            } else {
                m_mask |= 1 << i;
            }
            done = true;
        }
    }
    return done;
}
