struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Quat {
    float x, y, z, w;
    void Identity() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Comp_00277F48 : ObjComponent {
    int m1C[5];
    Quat m30;
    Comp_00277F48();
    virtual void Update();
    virtual ~Comp_00277F48();
};

Comp_00277F48::~Comp_00277F48()
{
}
