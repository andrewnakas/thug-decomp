struct Base_001D0708 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    virtual void V0_001D0708();
    virtual void V1_001D0708();
    virtual void V2_001D0708();
    virtual void V3_001D0708();
    virtual void V4_001D0708();
    virtual bool IsDone_001D0708();
    virtual void V6_001D0708();
    virtual void V7_001D0708();
    virtual void V8_001D0708();
    virtual void V9_001D0708();
    virtual void V10_001D0708();
    virtual int Start_001D0708();
};

struct Self_001D0708 {
    int m0;
    int m4;
    int m8;
    void* m_list;
};

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" Base_001D0708* func_001D0E90(void* list, const unsigned int& name, int a);
extern "C" void func_0010ED38(int a);
extern "C" int func_001D0208(Self_001D0708* self, const char* name, int a, int b, int c, int d, int e, int f);
extern "C" int func_001E53A0(unsigned int name, int a);

int func_001D0708(Self_001D0708* self, const char* name, int a, int b, int c, int d, int e, int f)
{
    unsigned int crc = func_001F0D78(name);
    Base_001D0708* task = func_001D0E90(self->m_list, crc, 1);
    int result;
    if (task) {
        result = task->Start_001D0708();
        while (!task->IsDone_001D0708()) {
            func_0010ED38(0);
        }
    } else {
        result = func_001D0208(self, name, a, b, c, 0, e, f);
    }
    func_001E53A0(0x25DC7904, 0);
    return result;
}
