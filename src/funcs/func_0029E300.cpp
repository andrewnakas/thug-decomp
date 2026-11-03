struct Sub_0029E300 {
    char pad[0x1C];
    int m1C;
};

extern "C" float func_001E5318(unsigned int name, int a);
extern "C" float func_0010FAB8();
extern "C" void func_001848F0(void* obj, unsigned int name, int a);

struct Obj_0029E300 {
    char pad[0xC];
    void* m0C;
    char pad2[0x1C - 0x10];
    int m1C;
    float m20;
    char pad3[0x28 - 0x24];
    Sub_0029E300* m28;
    void Update();
};

void Obj_0029E300::Update()
{
    if (m1C == 1) {
        int lvl = m28->m1C;
        if (lvl < 5) {
            if (lvl >= 2) {
                float k = func_001E5318(0x92FB4D09, 0);
                m20 -= k * func_0010FAB8();
                goto done;
            }
        }
        m20 -= func_0010FAB8();
    done:
        if (m20 < 0.0f) {
            m1C = 3;
            func_001848F0(m0C, 0x9E22A8E9, 0);
        }
    } else if (m1C == 3) {
        func_001848F0(m0C, 0x9E22A8E9, 0);
    }
}
