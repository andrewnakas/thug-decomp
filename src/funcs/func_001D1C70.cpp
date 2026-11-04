struct Target_001D1C70 {
    char pad[0x20];
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual int Update();
};

struct Obj_001D1C70 {
    char pad[0x24];
    Target_001D1C70* m_target;
    int Run();
};

int Obj_001D1C70::Run()
{
    return m_target->Update();
}
