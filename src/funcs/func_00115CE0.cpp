struct Obj_00115CE0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    unsigned int m_count : 16;
    unsigned int m_f16 : 1;
    unsigned int m_f17 : 1;
    unsigned int m_f18 : 1;
    Obj_00115CE0* Reset();
};

Obj_00115CE0* Obj_00115CE0::Reset()
{
    m_f17 = 0;
    m_f16 = 0;
    m_count = 0;
    m0 = 0;
    m8 = 0;
    mC = 0;
    m_f18 = 0;
    m10 = 0;
    m18 = 0;
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m34 = 0;
    m38 = 0;
    m30 = 0;
    m2C = 0;
    m28 = 0;
    return this;
}
