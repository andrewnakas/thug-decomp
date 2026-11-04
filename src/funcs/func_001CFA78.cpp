struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Slot_001CFA78 {
    int m[0x10 / 4];
    Slot_001CFA78() {}
};

struct Comp_001CFA78 : ObjComponent {
    Slot_001CFA78 m1C[4];
    Comp_001CFA78();
    virtual void Update();
    virtual ~Comp_001CFA78();
};

Comp_001CFA78::Comp_001CFA78()
{
    m_type = 0x9649D4F9;
}
