struct Target_001D1CD0 {
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
    virtual void Slot9();
    virtual void Slot10();
    virtual int Update();
};

struct Obj_001D1CD0 {
    char pad[0x24];
    Target_001D1CD0* m_target;
    int Run();
};

int Obj_001D1CD0::Run()
{
    return m_target->Update();
}
