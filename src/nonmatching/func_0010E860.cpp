/* fuzzy: 93.5 */
extern volatile int D_00388C90;
extern "C" int func_001092D0();
extern "C" void* func_00109328(const char* name, char* mode, int a);
extern char D_00388C88[];

class Job_0010E860 {
public:
    volatile int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    volatile int m1C;
    int m20;
    int m24;
    volatile int m28;
    volatile int m2C;
    void* m30;
    volatile int m34;
    int Bump() { return ++m34; }
    virtual void V1();
    virtual void Done(int state, int result, int err);
    virtual void V3();
    virtual bool OpenFallback(const char* name);
    virtual bool CloseFallback();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual int LoadFallback(void* buf);
    virtual int ReadFallback(void* buf, int size, int count);
    virtual void V16();
    virtual void V17();
    virtual int SeekFallback(int offset, int whence);
    bool Open(const char* name, int a, int b);
};

bool Job_0010E860::Open(const char* name, int a, int b)
{
    m10 = 1;
    m24 = b;
    m1C = a;
    if (func_001092D0() && (m30 = func_00109328(name, D_00388C88, 1)) != 0) {
        m0 = 1;
        m1C = 1;
        D_00388C90++;
        Bump();
        Done(m10, m0, 0);
        return m0 != 0;
    }
    return OpenFallback(name);
}
