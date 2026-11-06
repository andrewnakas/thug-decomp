extern "C" float func_0010FAB8();
extern int D_00394128;

struct Obj_001EEF80;

struct Handler_001EEF80 {
    char m_pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void Handle(Obj_001EEF80* o);
};

struct Obj_001EEF80 {
    char m_pad0[0x98];
    int m98;
    int m9C;
    int mA0;
    int mA4;
    Handler_001EEF80* mA8;
    void Update();
};

void Obj_001EEF80::Update()
{
    switch (mA4) {
    case 0:
        break;
    case 1:
        if (m98 == 0)
            mA4 = 0;
        else
            m98 = m98 - 1;
        break;
    case 10:
        if (m98) {
            m98 = m98 - 1;
        } else if (D_00394128 == 0) {
            D_00394128 = 1;
            mA4 = 0;
        }
        break;
    case 2: {
        int t = (int)(func_0010FAB8() * 1000.0f);
        if (mA0 < t) {
            if (m9C == 0)
                mA4 = 0;
            else
                mA0 = 0;
        } else {
            mA0 = mA0 - t;
        }
        m9C = 0;
        break;
    }
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        mA8->Handle(this);
        break;
    }
}
