extern "C" short func_0013E9D8(void* self);

class C_0013EBF8 {
public:
    char m_pad0[0xA0];
    int m_keys[18];
    int m_mask;
    bool IsHidden(int key);
};

bool C_0013EBF8::IsHidden(int key)
{
    bool result = true;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        if (key == m_keys[i]) {
            int bit = 1 << i;
            if (m_mask & bit) {
                result = false;
            }
        }
    }
    return result;
}
