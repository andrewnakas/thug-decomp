struct Comp_001EAFA8 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m_type;
    char m_pad3[0xC - 3];
    union {
        int i;
        float f;
    } m_val;
};

extern "C" Comp_001EAFA8* func_001E5040(int key);

struct Obj_001EAFA8 {
    unsigned char m0;
    unsigned char m_type;
    char m_pad2[6];
    union {
        int i;
        float f;
    } m_val;
    void Resolve();
};

void Obj_001EAFA8::Resolve()
{
    if (m_type != 13)
        return;
    Comp_001EAFA8* c = func_001E5040(m_val.i);
    if (!c)
        return;
    switch (c->m_type) {
    case 2:
        m_type = 2;
        m_val.f = c->m_val.f;
        break;
    case 1:
        m_type = 1;
        m_val.i = c->m_val.i;
        break;
    case 6:
        m_type = 6;
        m_val.i = c->m_val.i;
        break;
    case 5:
        m_type = 5;
        m_val.i = c->m_val.i;
        break;
    case 3:
        m_type = 3;
        m_val.i = c->m_val.i;
        break;
    case 4:
        m_type = 4;
        m_val.i = c->m_val.i;
        break;
    case 10:
        m_type = 10;
        m_val.i = c->m_val.i;
        break;
    case 12:
        m_type = 12;
        m_val.i = c->m_val.i;
        break;
    }
}
