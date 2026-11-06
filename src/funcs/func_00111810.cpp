extern volatile int D_00388C90;
class Job_00111810;
extern "C" int func_0010E748(Job_00111810* self, int offset, int whence);
extern "C" int func_0010E4B0(Job_00111810* self);
extern "C" int func_0010E558(Job_00111810* self);

class Job_00111810 {
public:
    volatile int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    volatile int m2C;
    void* m30;
    volatile int m34;
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
    int Bump() { return ++m34; }
    void Reread(void* buf);
};

void Job_00111810::Reread(void* buf)
{
    if (m2C) {
        func_0010E748(this, 0, 0);
        func_0010E4B0(this);
        m10 = 2;
    }
    ReadFallback(buf, 1, func_0010E558(this));
}
