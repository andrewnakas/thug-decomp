extern "C" void* func_001E55B8(int id, int flags);
extern "C" void* func_001E9378(void* scr, int arg);
extern "C" int func_001E8248(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7C80(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E9300(int id, int flags);
extern "C" int func_001E91C0(int id);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_001F0D78(const char* name);
extern "C" int func_001E8180(void* params, unsigned int name, int* out, int req);
extern "C" void func_002919B0(void* p);
extern "C" void func_00184AB0(void* obj, int a, int b);
extern "C" int func_001EFDC0(void* p);
extern char D_0038CF80[];

struct Obj_001AEEA0 {
    int m_pad[5];
    void* m14;
    int m18;
    int m1C;
};

struct Flag_001AEEA0 {
    int m_pad[78];
    int m138;
};

struct C_001AEEA0 {
    int m_pad[3];
    Obj_001AEEA0* mC;
    int m10[7];
    int* m2C;
    void* m30;
    Flag_001AEEA0* m34;
    int m38[652];
    int mA68;
    void* mA6C;
    int mA70[545];
    int m12F4;
    int m12F8;
    int m12FC;
    int m1300[2];
    int m1308;
    int Start(int a, int b, int c, int d);
};

extern "C" void func_001B0E78(C_001AEEA0* self);

int C_001AEEA0::Start(int a, int b, int c, int d)
{
    char buf[112];
    if (m12F4) {
        m12F4 = 0;
        void* scr = func_001E55B8(m12F8, 0);
        if (scr) {
            void* params = func_001E9378(scr, m12FC);
            int x = 0;
            func_001E8248(params, 0x22E168C1, &x, 0);
            int y = 0;
            func_001E8248(params, 0x689FE07C, &y, 0);
            int z = 0;
            func_001E7C80(params, 0x6C4E7971, &z, 0);
            if (!x && !y) {
                unsigned int n = 0;
                func_001E8398(params, 0xA92A2280, &n, 0);
                if (n) {
                    unsigned int q = 0;
                    func_001E8398(mA6C, n, &q, 0);
                    if (q) {
                        void* s = func_001E5548(q, 0);
                        if (s) {
                            func_001E8248(s, 0x22E168C1, &x, 0);
                            func_001E8248(s, 0x689FE07C, &y, 0);
                            func_001E7C80(s, 0x6C4E7971, &z, 0);
                        }
                    }
                }
            }
            int flags = 0;
            if (a) flags |= 1;
            if (b) flags |= 2;
            if (c) flags |= 4;
            if (d) flags |= 8;
            int r;
            if (x) {
                r = func_001E9300(x, flags);
            } else {
                int nm = func_001E91C0(y);
                func_003331D0(buf, D_0038CF80, z, nm);
                r = func_001F0D78(buf);
            }
            int w = 0;
            func_001E8180(params, 0x7031F10C, &w, 0);
            Obj_001AEEA0* o = mC;
            if (o->m1C == 1) m2C[0x42C / 4] = 0;
            mA68 = m1308;
            func_002919B0(m30);
            func_00184AB0(o, r, w);
            func_001EFDC0(o->m14);
            m34->m138 = 1;
            func_001B0E78(this);
            return 1;
        }
    }
    return 0;
}
