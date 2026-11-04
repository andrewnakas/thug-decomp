struct Obj_00273820 {
    char pad[0x18];
    virtual void Slot0();
    virtual void Slot1();
    virtual void Update(int a);
    void Run(int a);
};

void Obj_00273820::Run(int a)
{
    Update(a);
}
