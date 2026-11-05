struct Res_00134660 {
    int m0[8];
    int m_20;
    int m_24;
};

class Obj_00134660 {
public:
    char pad[0x280];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual Res_00134660* V7();
    Res_00134660* Clear();
};

Res_00134660* Obj_00134660::Clear()
{
    Res_00134660* r = V7();
    r->m_20 = 0;
    r->m_24 = 0;
    return r;
}
