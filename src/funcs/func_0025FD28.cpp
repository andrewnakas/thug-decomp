class Handler_0025FD28 {
public:
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual bool Handle(int a, int b, int c);
};

struct Obj_0025FD28 {
    bool OnEvent(int a, int b, int c);
};

extern "C" Handler_0025FD28* func_0025F128(Obj_0025FD28* self, int a);
extern "C" bool func_001842E0(Obj_0025FD28* self, int a, int b, int c);

bool Obj_0025FD28::OnEvent(int a, int b, int c)
{
    bool r = func_0025F128(this, 0)->Handle(a, b, c);
    if (!r)
        r = func_001842E0(this, a, b, c);
    return r;
}
