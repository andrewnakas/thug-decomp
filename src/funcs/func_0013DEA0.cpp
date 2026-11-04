extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013CA70(void* p);
extern "C" void func_00131178(float h, float s, float v, float* r, float* g, float* b);

struct S_0013DEA0 {
    unsigned char r, g, b, a;
};

extern "C" void func_0013C438(void* p, const S_0013DEA0& c);

class C_0013DEA0 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int m_keys[18];
    bool SetColour(int key, float h, float s, float v);
};

bool C_0013DEA0::SetColour(int key, float h, float s, float v)
{
    bool any = (key == (int)0xC4E78E22);
    bool done = false;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        if (key == m_keys[i] || any) {
            if (!func_0013CA70(m_items[i])) {
                float r, g, b;
                func_00131178(h, s, v, &r, &g, &b);
                done = true;
                S_0013DEA0 c;
                c.a = 0xFF;
                c.r = (int)(r * 255.0f + 0.5f);
                c.g = (int)(g * 255.0f + 0.5f);
                c.b = (int)(b * 255.0f + 0.5f);
                func_0013C438(m_items[i], S_0013DEA0(c));
            }
        }
    }
    return done;
}
