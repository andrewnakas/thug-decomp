struct Src_001DC540 {
    int m_0;
    int m_4;
};

extern Src_001DC540* D_0038E0A0;

struct Obj_001DC540 {
    char m_pad[0x14];
    int m_14;
    Obj_001DC540* Init();
};

Obj_001DC540* Obj_001DC540::Init()
{
    if (D_0038E0A0) {
        m_14 = D_0038E0A0->m_4;
    } else {
        m_14 = 0;
    }
    return this;
}
