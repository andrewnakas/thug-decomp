extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_00104418(char* s);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" short func_0013E9D8(void* self);
extern "C" int func_001392D0(void* p, char* a, char* b);
extern "C" void func_001E53A0(int id, int a);
extern char D_0038A290[];

class C_0013DAC0 {
public:
    char m_pad0[0x58];
    void* m_targets[18];
    int m_keys[70];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int Lock();
    virtual int Unlock();
    bool Send(int key, const char* a, const char* b);
};

bool C_0013DAC0::Send(int key, const char* a, const char* b)
{
    bool any = (key == (int)0xC4E78E22);
    bool sent = false;
    char buf[0x200];
    char buf2[0x200];
    Lock();
    func_00331A9C(buf, a);
    func_00104418(buf);
    if (!func_003364D8(buf, D_0038A290)) {
        func_00331678(buf, D_0038A290);
    }
    func_00331A9C(buf2, b);
    func_00104418(buf2);
    char* p = func_003364D8(buf2, D_0038A290);
    if (p) {
        *p = 0;
    }
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        if (key == m_keys[i] || any || m_keys[i] == 0) {
            void* t = m_targets[i];
            if (t) {
                if (func_001392D0(t, buf, buf2)) {
                    sent = true;
                }
            }
        }
    }
    if (!sent) {
        func_001E53A0(0x2A648514, 0);
    }
    Unlock();
    return sent;
}
