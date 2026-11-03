extern "C" short func_0013E9D8(void* self);
extern "C" void func_0013C478(void* p);

class C_0013DDE0 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int m_keys[18];
    bool Trigger(int key);
};

bool C_0013DDE0::Trigger(int key)
{
    bool any = (key == (int)0xC4E78E22);
    bool done = false;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        if (key == m_keys[i] || any) {
            func_0013C478(m_items[i]);
            done = true;
        }
    }
    return done;
}
