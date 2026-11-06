struct Msg_001A12B8 {
    unsigned char m0;
    char pad1;
    unsigned short m2;
    void* m4;
    char pad8[0xC];
    int m14;
    char pad18[8];
};

struct Sub_001A12B8 {
    char pad[0x18];
    int m18;
};

struct Node_001A12B8 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void Send(unsigned int id, void* params, int n);
};

extern void* D_00392068;
extern unsigned char D_0038CBCC;
extern "C" void* func_002A52F0(void* p, unsigned short id);
extern "C" int func_002B1FC8(void* p);
extern "C" int func_002B30A0(void* p);
extern "C" void* func_002A39E0(void* p, int a);
extern "C" void func_001FA800(Msg_001A12B8* m);
extern "C" void func_00200C00(void* p, Msg_001A12B8* m);
extern "C" Node_001A12B8* func_001A0718(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E72B0(void* p, unsigned int id, float v);
extern "C" void func_001E6AE8(void* p, int flags);

struct Obj_001A12B8 {
    int m0, m4, m8;
    Sub_001A12B8* mC;
    void SetVolume(int send, float vol);
};

void Obj_001A12B8::SetVolume(int send, float vol)
{
    if (send) {
        void* mgr = D_00392068;
        void* s = func_002A52F0(mgr, mC->m18);
        if (s && func_002B1FC8(s)) {
            void* dst = func_002A39E0(mgr, func_002B30A0(s));
            if (vol < 0.0f) {
                vol = 0.0f;
            } else if (vol > 1.0f) {
                vol = 1.0f;
            }
            unsigned char buf[2];
            buf[1] = (int)(vol * 255.0f);
            int id = mC->m18;
            buf[0] = id;
            if (D_0038CBCC != buf[1]) {
                Msg_001A12B8 m;
                func_001FA800(&m);
                m.m0 = 0x2B;
                m.m2 = 2;
                m.m4 = buf;
                m.m14 = 1;
                func_00200C00(dst, &m);
                D_0038CBCC = buf[1];
            }
        }
    }
    if (func_001A0718(this)) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E72B0(p, 0x4D747FA0, vol);
        func_001A0718(this)->Send(0xD0209498, p, 0);
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
}
