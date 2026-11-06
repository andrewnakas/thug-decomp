typedef int qword __attribute__((mode(TI)));
union Vec_0019C9D8 { qword q; float c[4];
    Vec_0019C9D8& operator=(const Vec_0019C9D8& o) { q = o.q; return *this; } };
struct Ref_0019C9D8;
extern "C" void func_00183CB8(void* obj, Ref_0019C9D8* ref);
extern "C" void func_00183C98(void* obj, Ref_0019C9D8* ref);
struct Ref_0019C9D8 {
    void* m_p; void* m_4; void* m_8;
    Ref_0019C9D8& operator=(const Ref_0019C9D8& o)
    {
        if (m_p) { func_00183CB8(m_p, this); m_p = 0; }
        m_p = o.m_p;
        if (m_p) func_00183C98(m_p, this);
        return *this;
    }
};
struct Sub_0019C9D8 {
    Vec_0019C9D8 m_0; Vec_0019C9D8 m_10; int m_20; char pad[0xC]; float m_30;
    unsigned short m_34, m_36, m_38; int m_3C, m_40, m_44, m_48, m_4C, m_50, m_54;
    unsigned char m_58, m_59;
    Sub_0019C9D8& operator=(const Sub_0019C9D8& o)
    {
        m_0 = o.m_0; m_10 = o.m_10; m_20 = o.m_20; m_30 = o.m_30;
        m_34 = o.m_34; m_36 = o.m_36; m_38 = o.m_38;
        m_3C = o.m_3C; m_40 = o.m_40; m_44 = o.m_44; m_48 = o.m_48; m_4C = o.m_4C; m_50 = o.m_50; m_54 = o.m_54;
        m_58 = o.m_58; m_59 = o.m_59;
        return *this;
    }
};
struct Obj_0019C9D8 {
    Vec_0019C9D8 m_0; Vec_0019C9D8 m_10; int m_20; char pad[0xC];
    Sub_0019C9D8 m_30; float m_90; char pad3[0xC];
    Vec_0019C9D8 m_A0; Vec_0019C9D8 m_B0; Ref_0019C9D8 m_C0; int m_CC; int m_D0; int m_D4;
    Obj_0019C9D8& operator=(const Obj_0019C9D8& o);
};
Obj_0019C9D8& Obj_0019C9D8::operator=(const Obj_0019C9D8& o)
{
    m_0 = o.m_0; m_10 = o.m_10; m_20 = o.m_20;
    m_30 = o.m_30;
    m_90 = o.m_90;
    m_A0 = o.m_A0; m_B0 = o.m_B0;
    m_C0 = o.m_C0;
    m_CC = o.m_CC; m_D0 = o.m_D0; m_D4 = o.m_D4;
    return *this;
}
