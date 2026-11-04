struct Target_001D1C00 {
    char pad[0x20];
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual int Update();
};

struct Obj_001D1C00 {
    char pad[0x24];
    Target_001D1C00* m_target;
    int Run();
};

int Obj_001D1C00::Run()
{
    return m_target->Update();
}
