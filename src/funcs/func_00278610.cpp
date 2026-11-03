struct Obj_00278610 {
    char pad[0x18];
    virtual void Slot0();
    virtual void Slot1();
    virtual void Update(int a);
    void Run(int a);
};

void Obj_00278610::Run(int a)
{
    Update(a);
}
