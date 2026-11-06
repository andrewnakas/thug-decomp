struct Obj_001D4C20 {
    int m0;
    int m4;
    int m8;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int V7();
};

struct Node_001D4C20 {
    int m0;
    Obj_001D4C20* m4;
    int m8;
    Node_001D4C20* mC;
    Node_001D4C20* Valid() { if (~(int)m4 == 0) return 0; return this; }
    Obj_001D4C20* GetData() { return m4; }
};

struct Owner_001D4C20 {
    char pad[0x10];
    Node_001D4C20* m10;
    void Run();
};

void Owner_001D4C20::Run()
{
    m10->mC->Valid()->GetData()->V7();
}
