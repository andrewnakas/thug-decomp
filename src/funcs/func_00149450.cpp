class Obj_00149450 {
public:
    char pad[0xC];
    unsigned short m_w;
    unsigned short m_h;
    char pad10[0x14];
    unsigned char* m_24;
    unsigned char* m_28;
    bool Scale(int orig, float s);
    unsigned char* GetSrc(int orig)
    {
        if (m_24 && !orig) return m_24;
        return m_28;
    }
};

static inline float Min_00149450(float a, float b)
{
    return b < a ? b : a;
}

bool Obj_00149450::Scale(int orig, float s)
{
    unsigned char* dst = m_28;
    unsigned char* src = GetSrc(orig);
    int n = m_w * m_h;
    int i;
    for (i = 0; i < n; i++) {
        dst[0] = (int)Min_00149450(src[0] * s, 255.0f);
        dst[1] = (int)Min_00149450(src[1] * s, 255.0f);
        dst[2] = (int)Min_00149450(src[2] * s, 255.0f);
        src += 4;
        dst += 4;
    }
    return true;
}
