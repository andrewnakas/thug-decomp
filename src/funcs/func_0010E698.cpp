extern volatile int D_00388C90;
extern "C" int func_00109458(void* dst, int size, int count, void* file);

class Job_0010E698 {
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
    virtual int OpenFallback(const char* name);
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

    int Read(void* buf, int size, int count);
};

int Job_0010E698::Read(void* buf, int size, int count)
{
    m10 = 3;
    if (m30) {
        m0 = func_00109458(buf, size, count, m30);
        D_00388C90++;
        Bump();
        Done(m10, m0, 0);
        return m0;
    }
    return ReadFallback(buf, size, count);
}
