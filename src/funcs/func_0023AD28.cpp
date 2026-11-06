struct Bytes_0023AD28 {
    unsigned char m[0x9C4];
    unsigned char* At(int i) { return &m[i]; }
};

struct Obj_0023AD28 {
    char pad[0x1A8];
    Bytes_0023AD28 m_1A8;
    Bytes_0023AD28 m_B6C;
    int m_1530;
    int m_1534;
    int m_1538;
    int m_153C;
    int m_1540;
    float m_1544;
    void Use(int i);
};

extern "C" int func_001E53A0(unsigned int name, int def);

static inline float Frac_0023AD28(int v, const int& max)
{
    float m = (float)max;
    return (float)(max - v) / m;
}

static inline float Max_0023AD28(float a, float b)
{
    return a < b ? b : a;
}

void Obj_0023AD28::Use(int i)
{
    float r;
    if (i < 0x9C4) {
        m_1530++;
        m_1534++;
        unsigned char* a = m_1A8.At(i);
        if (*a == 0) {
            m_1538++;
            m_153C++;
        }
        if (*a < 0xFF) {
            (*a)++;
        }
        unsigned char* b = m_B6C.At(i);
        if (*b == 0) {
            m_1540++;
        }
        if (*b < 0xFF) {
            (*b)++;
        }
        int lim = func_001E53A0(0x6EE127B7, 0);
        if (lim < *b) {
            r = (1.0f / (float)(*b - lim + 1)) * Frac_0023AD28(*a - 1, 20);
            r = Max_0023AD28(r, 0.1f);
            goto done;
        }
    }
    r = 1.0f;
done:
    m_1544 = r;
}
