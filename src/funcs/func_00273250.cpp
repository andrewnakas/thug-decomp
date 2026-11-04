class Comp_00273250 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Hide(bool hide);
};

struct Owner_00273250 {
    char pad0[0x104];
    unsigned int m_flags;
};

struct Mode_00273250 {
    char pad0[0x20];
    int m_type;
};

struct Obj_00273250 {
    char pad0[0xC];
    Owner_00273250* m_owner;
    char pad10[0x1C - 0x10];
    bool m_hidden;
    char pad20[0x30 - 0x20];
    Comp_00273250* m_model;
    Mode_00273250* m_mode;
    void Hide(bool hide);
};

extern "C" Comp_00273250* func_00185578(void* obj, unsigned int name);

void Obj_00273250::Hide(bool hide)
{
    m_hidden = hide;
    if (!hide && (m_owner->m_flags & 2)) {
        return;
    }
    switch (m_mode->m_type) {
    case 0:
        m_model->Hide(hide);
        func_00185578(m_owner, 0x52D61A0D)->Hide(hide);
        func_00185578(m_owner, 0x9F9CC949)->Hide(hide);
        func_00185578(m_owner, 0x9B373E58)->Hide(hide);
        break;
    case 1:
        func_00185578(m_owner, 0x726E85AA)->Hide(hide);
        break;
    }
}
