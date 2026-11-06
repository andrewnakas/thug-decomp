class Quad_0014A230 {
public:
    char pad[0x3C];
    virtual ~Quad_0014A230();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
};

class Spr_0014A230 : public Quad_0014A230 {
public:
    void Refresh();
};

void Spr_0014A230::Refresh()
{
    V3();
    V4();
    V2();
    V5();
}
