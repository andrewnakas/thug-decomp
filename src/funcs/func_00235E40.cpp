struct Props_00235E40 {
    char m0;
    char m_pad1[7];
    int m8;
    int mC;
    char m10;
    char m_pad11[0xF];
};

struct Obj_00235E40 {
    char m_pad[0x1C];
    void* m1C;
    void* m20;
};

extern void* D_00392068;

extern "C" bool func_002A1A38(void* self);
extern "C" Props_00235E40* func_001FA800(Props_00235E40* self);
extern "C" void* func_002A39D8(void* self);
extern "C" int func_002A1968(void* self);
extern "C" void func_002A3988(void* self);
extern "C" void func_001FF970(void* self, int a, Props_00235E40* props);
extern "C" void func_002010D0(void* self, int a);
extern "C" void func_002A37D8(void* self);
extern "C" void func_001048F0(void* p);
extern "C" void* func_002A39E0(void* self, int a);
extern "C" void func_00200C00(void* self, Props_00235E40* props);
extern "C" void func_002A58C8(void* self);

void func_00235E40(Obj_00235E40* self)
{
    void* mgr = D_00392068;
    Props_00235E40 props;
    if (func_002A1A38(mgr)) {
        func_001FA800(&props);
        void* elem = func_002A39D8(mgr);
        if (func_002A1968(mgr) == 1) {
            func_002A3988(mgr);
        }
        props.m0 = 0x32;
        props.m8 = 0xFF;
        func_001FF970(elem, 0xFF, &props);
        func_002010D0(elem, 0);
        func_002A37D8(mgr);
        func_001048F0(self->m1C);
        func_001048F0(self->m20);
    } else {
        void* elem = func_002A39E0(mgr, 0);
        if (elem) {
            func_001FA800(&props);
            props.m0 = 0xB;
            props.mC = 2;
            props.m10 = 8;
            func_00200C00(elem, &props);
            func_002010D0(elem, 0);
        }
    }
    func_002A58C8(mgr);
}
