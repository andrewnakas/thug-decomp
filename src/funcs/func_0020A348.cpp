struct Vec_0020A348 {
    float c[4];
    Vec_0020A348() {}
    Vec_0020A348(float ax, float ay, float az, float aw) { c[0] = ax; c[1] = ay; c[2] = az; c[3] = aw; }
    const float& operator[](int i) const { return c[i]; }
};

static inline Vec_0020A348 operator+(const Vec_0020A348& a, const Vec_0020A348& b)
{
    return Vec_0020A348(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

extern "C" void func_001235E8(const Vec_0020A348* a, const Vec_0020A348* b, unsigned int c0, unsigned int c1, int flag);

static inline void Line_0020A348(const Vec_0020A348& a, const Vec_0020A348& b, unsigned int c, int flag)
{
    func_001235E8(&a, &b, c, c, flag);
}

struct Seg_0020A348 {
    Vec_0020A348 a;
    char pad10[0x20];
    Vec_0020A348 b;
    char pad40[0x40];
};

struct Box_0020A348 {
    Vec_0020A348 m0;
    Vec_0020A348 m10;
    Vec_0020A348 m20;
    Seg_0020A348 m30[32];
    int m1030;
    char pad1034[0xC];
    Seg_0020A348 m1040[32];
    int m2040;
    void Draw(int r, int g, int b, int flag);
};

void Box_0020A348::Draw(int r, int g, int b, int flag)
{
    unsigned int col = 0xFF000000 | (b << 16) | (g << 8) | r;
    Line_0020A348(m0, m0 + m10, col, flag);
    Line_0020A348(m0 + m10, m0 + m10 + m20, col, flag);
    Line_0020A348(m0 + m10 + m20, m0 + m20, col, flag);
    Line_0020A348(m0 + m20, m0, col, flag);
    if (m2040 > 0) {
        int i = m2040;
        while (i--) {
            g += 0x63;
            b += 0x1F;
            r += 0xC9;
            col = 0xFF000000 | (b << 16) | (g << 8) | r;
            Line_0020A348(m1040[i].a, m1040[i].b, col, 1);
        }
    } else {
        int i = m1030;
        while (i--) {
            g += 0x63;
            b += 0x1F;
            r += 0xC9;
            col = 0xFF000000 | (b << 16) | (g << 8) | r;
            Line_0020A348(m30[i].a, m30[i].b, col, 1);
        }
    }
}
