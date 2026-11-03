struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Pool_001CECA8;
extern Pool_001CECA8* D_0038E0A0;
extern "C" void func_001DD448(Pool_001CECA8* pool, void* p);

struct Comp_001CEC38 : ObjComponent {
    int m1C;
    int m20;
    void* m24;
    void* m28;
    Comp_001CEC38();
    virtual void Update();
    virtual ~Comp_001CEC38();
};

Comp_001CEC38::~Comp_001CEC38()
{
    if (m24) {
        func_001DD448(D_0038E0A0, m24);
        m24 = 0;
    }
    if (m28) {
        func_001DD448(D_0038E0A0, m28);
        m28 = 0;
    }
}
