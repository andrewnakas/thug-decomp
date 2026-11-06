class Target_0010A6D0 {
public:
    int m[32];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int V4();
};

struct Ref_0010A6D0 {
    Target_0010A6D0* m_obj;
};

class Obj_0010A6D0 {
public:
    char pad[0x8C];
    Ref_0010A6D0* m_ref;
    int Call();
};

int Obj_0010A6D0::Call()
{
    return m_ref->m_obj->V4();
}
