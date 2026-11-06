struct Player_0022CBF8 {
    char pad[0x30];
    int m_30;
};

extern void* D_00392068;
extern char D_0038FCA0[];
extern char D_003729D0[];
extern char D_0038FC90[];
extern char D_0038FC98[];
extern char D_003729E0[];
extern char D_003729F8[];
extern char D_00372A10[];
extern char D_00372A28[];
extern char D_00372A40[];
extern char D_00372A50[];
extern char D_00372A90[];
extern char D_00372AA0[];
extern char D_0038FCA8[];
extern char D_00372AB0[];
extern char D_00372AE8[];
extern "C" bool func_0022EF38(void* self);
extern "C" void* func_0022E358(void* self);
extern "C" bool func_0024F540(void* p);
extern "C" unsigned int func_0024F938(void* p);
extern "C" bool func_0024F860(void* p);
extern "C" bool func_0024F8D8(void* p, char* name);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_00258698(unsigned int name, int a, int b);
extern "C" Player_0022CBF8* func_002A56E0(void* net);
extern "C" int func_00229758(char* name);
extern "C" int func_002A6D98(void* net, int idx);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00252B38(void* p);

struct Sk_0022CBF8 {
    char pad[0x398];
    void* m_398;
    int GetModel(int idx);
};

int Sk_0022CBF8::GetModel(int idx)
{
    int r = -1;
    void* net = D_00392068;
    if (func_0022EF38(this)) {
        if (func_0024F540(func_0022E358(this))) {
            if (func_0024F938(func_0022E358(this)) == func_001F0D78(D_003729D0)) {
                r = func_00258698(func_001F0D78(D_0038FC90), 0, -1);
            } else if (func_0024F938(func_0022E358(this)) == func_001F0D78(D_0038FC98)) {
                Player_0022CBF8* p = func_002A56E0(net);
                if (p) {
                    switch (p->m_30) {
                    case 0:
                        r = func_00229758(D_003729E0);
                        break;
                    case 1:
                        r = func_00229758(D_003729F8);
                        break;
                    case 2:
                        r = func_00229758(D_00372A10);
                        break;
                    case 3:
                        r = func_00229758(D_00372A28);
                        break;
                    }
                }
            } else {
                idx = func_002A6D98(net, idx);
                r = func_00258698(func_001F0D78(D_00372A40), idx, -1);
                if (r != -1) {
                    return r;
                }
                func_00103F28(D_00372A50);
                r = func_00258698(func_001F0D78(D_0038FCA0), 0, -1);
            }
        } else if (func_0024F860(func_0022E358(this))) {
            char buf[0x20];
            func_003331D0(buf, D_00372A90, idx + 1);
            r = func_00258698(func_001F0D78(buf), 0, -1);
        } else if (func_0024F8D8(func_0022E358(this), D_00372AA0)) {
            unsigned int name = func_001F0D78(D_0038FCA8);
            r = func_00258698(name, func_00252B38(m_398), -1);
        } else {
            idx = func_002A6D98(net, idx);
            r = func_00258698(func_001F0D78(D_00372A40), idx, -1);
            if (r != -1) {
                return r;
            }
            func_00103F28(D_00372A50);
            r = func_00258698(func_001F0D78(D_0038FCA0), 0, -1);
        }
    } else {
        r = func_00258698(func_001F0D78(D_0038FCA0), idx, -1);
    }
    if (r == -1) {
        func_00103F28(D_00372AB0);
        r = func_00258698(0, 0, -1);
        if (r == -1) {
            func_00103F28(D_00372AE8);
        }
    }
    return r;
}
