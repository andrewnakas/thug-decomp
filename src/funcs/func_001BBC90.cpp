struct Timer_001BBC90 {
    int m0;
    int m4;
};

extern "C" Timer_001BBC90* func_0026F6C0(void* table, unsigned int id);
extern "C" unsigned int func_0010FC30();
extern "C" void* func_00185578(int obj, unsigned int name);
extern "C" int func_00183348(unsigned int id);
extern "C" void func_001B0E60(void* comp, int anim, float t);
extern "C" void func_0026FE08(Timer_001BBC90* t, float v);
extern "C" void func_0026FD00(Timer_001BBC90* t, int v);
extern "C" void func_0026FDC8(Timer_001BBC90* t);
extern "C" void func_0026FDD0(Timer_001BBC90* t);

struct C_001BB720 {
    int m_pad[3];
    int mC;
    int m10[5];
    int m24[2];
    void Play(unsigned int id, float speed, int loop);
};

void C_001BB720::Play(unsigned int id, float speed, int loop)
{
    Timer_001BBC90* timer = func_0026F6C0(m24, id);
    float t = (float)func_0010FC30() + speed * 1000.0f;
    void* comp = func_00185578(mC, 0x270F56E1);
    if (comp)
        func_001B0E60(comp, func_00183348(id), t);
    func_0026FE08(timer, (float)(int)t);
    if (loop) {
        func_0026FD00(timer, 0);
        func_0026FDC8(timer);
        func_0026FDD0(timer);
    }
}
