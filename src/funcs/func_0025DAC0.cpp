extern "C" bool func_001DF9F8();
extern "C" int func_001DFA30(float v);

struct Obj_0025DAC0;
extern "C" void func_0025D7C8(Obj_0025DAC0* self, int a, int b);

struct Obj_0025DAC0 {
    char m_pad[0xB60];
    int m_started;
    void Play(int a, int b);
};

void Obj_0025DAC0::Play(int a, int b)
{
    if (!m_started) {
        if (func_001DF9F8()) {
            func_001DFA30(-1.0f);
            m_started = 1;
            func_0025D7C8(this, a, b);
        }
    } else {
        func_0025D7C8(this, a, b);
    }
}
