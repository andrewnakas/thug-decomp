/* fuzzy: 85.8 */
/* sym: Turn__10C_001A6CA0PvPfifi = 0x001A7108 */
/* sym: Start__10C_001A6CA0i = 0x001A6A10 */
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);

struct Obj_001A6CA0 {
    int m_pad[20];
    float m50[4];
};

struct C_001A6CA0 {
    int m_pad[3];
    Obj_001A6CA0* mC;
    int m10[3];
    int m1C;
    int m20;
    int m24[79];
    float m160[3];
    int m16C[5];
    float m180[3];
    int m18C;
    float m190[3];
    int m19C;
    float m1A0[3];
    int Turn(void* script, float* rot, int mode, float angle, int axis);
    void Start(int axis);
    int Rotate(void* params, void* script);
};

int C_001A6CA0::Rotate(void* params, void* script)
{
    float time = 0.0f;
    int deg = 360;
    int speed = 0;
    int axes = 2;
    if (!(m1C & 0x40)) {
        m1C = (m1C | 0x40) & ~7;
        m20 &= ~0xE0;
    }
    func_001E7EB0(params, 0x906B67BA, &time, 0);
    if (time == 0.0f) {
        func_001E7DE8(params, 0xF0D90109, &deg, 0);
        func_001E7DE8(params, 0x85894A84, &speed, 0);
        func_001E7DE8(params, 0xA4AECB20, &axes, 0);
    }
    float angle = 0.0f;
    func_001E7EB0(params, 0xF73A4EFD, &angle, 0);
    angle *= 0.01745329425f;
    int any = 0;
    for (int i = 0; i < 3; i++) {
        if ((axes >> i) & 1) {
            if (Turn(script, mC->m50, i == 2 ? 1 : 2, angle, i)) {
                if (time != 0.0f) {
                    m1A0[i] = 0.0f;
                    m190[i] = m160[i] / time;
                } else {
                    m1A0[i] = speed * 0.01745329425f;
                    if (m1A0[i] == 0.0f) {
                        m190[i] = deg * 0.01745329425f;
                    } else {
                        m190[i] = 0.0f;
                        m180[i] = 0.0f;
                    }
                    Start(i);
                }
                any = 1;
            }
        }
    }
    return any;
}
