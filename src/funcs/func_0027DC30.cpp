extern "C" float func_002032A0(unsigned int name, int a);
extern "C" void func_0027DCA0(void* self);
extern "C" void func_0027DD38(void* self);

struct State_0027DC30 {
    char pad[0xA0];
    int mA0;
};

struct Obj_0027DC30 {
    char pad[0x364];
    int m364;
    char pad2[0x378 - 0x368];
    float m378;
    char pad3[0x5B0 - 0x37C];
    State_0027DC30* m5B0;
    void Update();
};

void Obj_0027DC30::Update()
{
    if (!m364 && !m5B0->mA0 && m378 == func_002032A0(0x78F80EC4, 0))
        return;
    func_0027DCA0(this);
    func_0027DD38(this);
}
