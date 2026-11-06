extern void* D_00392068;
extern "C" void func_002A19A8(void* net);

class Handler_001EF0B8 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual int Handle(int a, int b, void* owner);
};

struct Obj_001EF0B8 {
    char pad0[0x14];
    int m14;
    char pad18[0xBC - 0x18];
    Handler_001EF0B8* mBC;
};

extern "C" int func_001EF0B8(Obj_001EF0B8* o, int a, Handler_001EF0B8* h)
{
    Handler_001EF0B8* p = h ? h : o->mBC;
    int r = 0;
    if (p) {
        r = p->Handle(a, o->m14, o);
    } else {
        func_002A19A8(D_00392068);
    }
    return r;
}
