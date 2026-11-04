struct Comp_001CEDB8 {
    char pad[0x1C];
    int m1C;
    void Update();
};

extern "C" void func_001CEE80(Comp_001CEDB8* self);
extern "C" void func_001CF2F8(Comp_001CEDB8* self);
extern "C" void func_001CF548(Comp_001CEDB8* self);

void Comp_001CEDB8::Update()
{
    if (m1C) {
        func_001CEE80(this);
        func_001CF2F8(this);
        func_001CF548(this);
    }
}
