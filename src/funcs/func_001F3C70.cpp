struct Obj_001F3C70 {
    char pad[0x18];
    virtual void Slot0();
    virtual void Slot1();
    virtual void Update(int a);
    void Run(int a);
};

void Obj_001F3C70::Run(int a)
{
    Update(a);
}
