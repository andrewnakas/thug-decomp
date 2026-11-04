typedef int qword __attribute__((mode(TI)));

struct Vec_001C4638 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C4638() {}
    Vec_001C4638(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
};

struct Mat_001C4638 {
    Vec_001C4638 r0;
    Vec_001C4638 r1;
    Vec_001C4638 r2;
    Vec_001C4638 r3;
    Mat_001C4638& operator=(const Mat_001C4638& o)
    {
        r0 = o.r0;
        r1 = o.r1;
        r2 = o.r2;
        r3 = o.r3;
        return *this;
    }
};

struct Body_001C4638 {
    char m_pad0[0x50];
    Vec_001C4638 m50;
    char m_pad60[0x10];
    Mat_001C4638 m70;
};

struct Obj_001C4638 {
    char m_pad0[0xC];
    Body_001C4638* mC;
    char m_pad10[0xB4];
    float mC4;
    char m_padC8[0xC30 - 0xC8];
    Vec_001C4638 mC30;
    char m_padC40[4];
    float mC44;
    char m_padC48[8];
    Vec_001C4638 mC50;
    char m_padC60[0x10];
    Vec_001C4638 mC70;
    char m_padC80[4];
    void (Obj_001C4638::*mC84)();
    virtual void Dummy();
    void Update();
};

void Obj_001C4638::Update()
{
    mC->m50 = Vec_001C4638(mC30.x + mC70.x, mC30.y + mC70.y, mC30.z + mC70.z, mC30.w + mC70.w);
    Mat_001C4638 m;
    Vec_001C4638& right = m.r0;
    Vec_001C4638& up = m.r1;
    Vec_001C4638& pos = m.r3;
    m.r2 = mC50;
    up.Set(0.0f, 1.0f, 0.0f);
    right.Set(mC50.z, 0.0f, -mC50.x);
    pos.Set(0.0f, 0.0f, 0.0f);
    mC->m70 = m;
    mC4 = mC44;
    if (mC84) {
        (this->*mC84)();
    }
}
