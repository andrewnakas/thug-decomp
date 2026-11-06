extern "C" void func_00132418(void* p);

struct Obj_001D1A08 {
    char m_pad0[0x20];
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
    virtual int SetData(void* p);
    virtual void* GetData();
    int Release();
};

int Obj_001D1A08::Release()
{
    if (GetData()) {
        func_00132418(GetData());
        SetData(0);
    }
    return 0;
}
