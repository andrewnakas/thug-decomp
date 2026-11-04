struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Comp_001CE688 : ObjComponent {
    int m1C;
    int m20;
    Comp_001CE688();
    virtual void Update();
    virtual ~Comp_001CE688();
};

Comp_001CE688::Comp_001CE688()
{
    m_type = 0x408D2AA9;
    m1C = 0;
    m20 = 0;
}
