struct Sub_0029E630 {
    char pad[0x18];
    int m18;
    char pad2[0x320 - 0x1C];
    int m320;
};

extern void* D_0038C7B0;
extern "C" float func_00203D40(Sub_0029E630* o, unsigned int name);
extern "C" void func_00189750(void* p, unsigned int a, int b, int c, int d, int e);

struct Obj_0029E630 {
    char pad[0xC];
    Sub_0029E630* m0C;
    char pad2[0x1C - 0x10];
    int m1C;
    float m20;
    short m24;
    void Update();
};

void Obj_0029E630::Update()
{
    if (!m1C)
        return;
    m1C = (0.0f < m20) ? 1 : 3;
    if (m24 < 8) {
        float s = func_00203D40(m0C, 0x0B84F532);
        float v = (8 - m24) * s * 0.125f;
        m20 = m20 < v ? m20 : v;
    }
    m24++;
    func_00189750(D_0038C7B0, 0x47EEC244, m0C->m320 + 0x83321DEA, m0C->m18, 0, 0);
}
