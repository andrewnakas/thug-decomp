extern "C" void func_002756C8(void* self);
extern "C" void func_00276338(void* self);
extern "C" void func_00274948(void* self);

struct State_002768F0 {
    char pad[0x1C];
    int m1C;
};

struct Obj_002768F0 {
    char pad[0x2AC];
    State_002768F0* m2AC;
    char pad2[0x2B8 - 0x2B0];
    State_002768F0* m2B8;
    void Update();
};

void Obj_002768F0::Update()
{
    if (m2AC->m1C < 20)
        return;
    if (m2B8->m1C == 4) {
        func_002756C8(this);
    } else {
        func_00276338(this);
        func_00274948(this);
    }
}
