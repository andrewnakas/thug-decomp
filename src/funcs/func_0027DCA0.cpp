extern "C" float func_002032A0(unsigned int name, int a);
extern "C" void func_0027CBE0(void* self, float v);

struct State_0027DCA0 {
    char pad[0x28];
    int m28;
};

struct Obj_0027DCA0 {
    char pad[0x3B4];
    float m3B4;
    char pad2[0x3C0 - 0x3B8];
    float m3C0;
    char pad3[0x5B0 - 0x3C4];
    State_0027DCA0* m5B0;
    void Apply();
};

void Obj_0027DCA0::Apply()
{
    float a = func_002032A0(0xBED96EDA, 0);
    float b = func_002032A0(0x1A78B6FC, 0);
    if (m3B4 != 0.0f) {
        b = m3C0;
        a = b;
    }
    if (m5B0->m28)
        func_0027CBE0(this, a);
    else
        func_0027CBE0(this, b);
}
