struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Comp_001CF960 : ObjComponent {
    Comp_001CF960();
    virtual void Update();
    virtual ~Comp_001CF960();
};

Comp_001CF960::Comp_001CF960()
{
    m_type = 0x1BBF844D;
}
