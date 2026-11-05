extern "C" void* func_001D0E90(void* tbl, int* key, int a);
extern "C" void func_0010ED38(int a);

struct Res_001D0638 {
    char pad0[0x20];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int IsReady();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual int Get();
};

struct Mgr_001D0638 {
    char pad0[0xC];
    void* m_C;
    int Find(int key);
};

int Mgr_001D0638::Find(int key)
{
    Res_001D0638* r = (Res_001D0638*)func_001D0E90(m_C, &key, 1);
    if (r) {
        while (!r->IsReady()) {
            func_0010ED38(0);
        }
        return r->Get();
    }
    return 0;
}
