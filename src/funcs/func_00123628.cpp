typedef int qword __attribute__((mode(TI)));

extern "C" void* memcpy(void* d, const void* s, unsigned int n);

struct Node123628;

extern "C" void func_00183C98(void* list, Node123628* node);
extern "C" void func_00183CB8(void* list, Node123628* node);

struct Node123628 {
    void* m_list;
    Node123628* m_prev;
    Node123628* m_next;
    Node123628()
    {
        m_prev = 0;
        m_next = 0;
        m_list = 0;
    }
    void Set(void* o)
    {
        if (m_list) {
            func_00183CB8(m_list, this);
            m_list = 0;
        }
        m_list = o;
        if (o)
            func_00183C98(o, this);
    }
};

struct Vec123628 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec123628() {}
    Vec123628(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec123628& operator=(const Vec123628& v)
    {
        q = v.q;
        return *this;
    }
};

struct Color123628 {
    unsigned char r, g, b, a;
    Color123628() {}
    Color123628(unsigned char ar, unsigned char ag, unsigned char ab, unsigned char aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
    Color123628(const Color123628& c) { memcpy(this, &c, 4); }
};

struct Sub123628 {
    float m0;
    Vec123628 m10;
    float m20;
    float m24;
    int m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    Color123628 m48;
    void SetColor(Color123628 c)
    {
        m48.r = c.r;
        m48.g = c.g;
        m48.b = c.b;
        m48.a = c.a;
    }
    void Init()
    {
        m20 = 0.0f;
        m34 = 1.0f;
        m38 = 1.0f;
        m3C = 1.0f;
        m40 = 1.0f;
        m24 = 0.0f;
        m44 = 0.0f;
        m10 = Vec123628(0.0f, 0.0f, 0.0f, 1.0f);
        {
            Color123628 c(0x80, 0x80, 0x80, 0x80);
            SetColor(c);
        }
        m0 = 1.0f;
    }
};

struct B_00184EB8 {
    int m0;
    int m4;
    B_00184EB8();
    virtual void V0();
};

struct C_001238D0 : B_00184EB8 {
    unsigned int mC;
    char pad10[0x38];
    Node123628 m48;
    Node123628 m54;
    Node123628 m60;
    Node123628 m6C;
    char pad78[8];
    Sub123628 m80;
    Sub123628 mD0;
    char pad120[4];
    int m124;
    char pad128[8];
    Sub123628 m130;
    char pad180[8];
    int m188;
    int m18C;
    Color123628 m190;
    int m194;
    float m198;
    C_001238D0();
    virtual void V0();
    virtual ~C_001238D0();
};

C_001238D0::C_001238D0()
{
    m124 = 0;
    m48.Set(0);
    m54.Set(0);
    m6C.Set(0);
    m60.Set(0);
    m80.Init();
    mD0 = m80;
    m130 = m80;
    m188 = 0;
    m18C = 0;
    m190.r = 0x80;
    m190.g = 0x80;
    m190.b = 0x80;
    m190.a = 0x80;
    m194 = 0;
    m198 = 1.0f;
    mC |= 0x10400;
}
