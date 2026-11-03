struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Comp_001CE200 : ObjComponent {
    Comp_001CE200();
    virtual void Update();
    virtual ~Comp_001CE200();
};

Comp_001CE200::~Comp_001CE200()
{
}
