typedef int qword __attribute__((mode(TI)));

struct Vec_00272EA8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mtx_00272EA8 {
    Vec_00272EA8 r[4];
    const Vec_00272EA8& operator[](int i) const { return r[i]; }
    Mtx_00272EA8& operator=(const Mtx_00272EA8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Model_00272EA8 {
    char pad0[0x70];
    Mtx_00272EA8 m70;
    char padB0[0x10];
    Mtx_00272EA8 mC0;
};

struct Anim_00272EA8 {
    char pad0[8];
    unsigned int m8;
    char padC[0x14];
    Mtx_00272EA8 m20;
};

struct Mode_00272EA8 {
    char pad0[0x20];
    int m20;
};

struct Obj_00272EA8 {
    char pad0[0xC];
    Model_00272EA8* mC;
    char pad10[0xC];
    int m1C;
    char pad20[0xC];
    int m2C;
    Anim_00272EA8* m30;
    Mode_00272EA8* m34;
    void Update();
};

extern "C" void func_00273250(Obj_00272EA8* o, int f);

void Obj_00272EA8::Update()
{
    m2C = 0;
    if (!m1C) return;
    switch (m34->m20) {
    case 0:
        mC->mC0 = m30->m20;
        break;
    case 1:
        mC->mC0 = mC->m70;
        break;
    }
    if (m30->m8 & 1) return;
    func_00273250(this, 1);
}
