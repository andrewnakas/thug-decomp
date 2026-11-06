extern volatile int D_00388C90;
extern "C" int func_001094F8(void* file, int offset, int whence);

class Job_0010E748 {
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
    int Seek(int offset, int whence);
};

int Job_0010E748::Seek(int offset, int whence)
{
    m10 = 5;
    if (m30) {
        m0 = func_001094F8(m30, offset, whence);
        D_00388C90++;
        Bump();
        Done(m10, m0, 0);
        return m0;
    }
    return SeekFallback(offset, whence);
}
