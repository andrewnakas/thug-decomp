extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001A9E68(void* comp);

class Obj_0013FCB8 {
public:
    int m0[2];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void Stop();
    void Check();
};

void Obj_0013FCB8::Check()
{
    if (!func_001A9E68(func_00185578(this, 0xCE0CA665))) {
        Stop();
    }
}
