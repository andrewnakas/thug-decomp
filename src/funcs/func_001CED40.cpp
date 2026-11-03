extern "C" int func_00185578(int obj, unsigned int checksum);

struct Comp_001CED40 {
    char pad[0xC];
    int mC;
    char pad2[0xB8 - 0x10];
    int mB8;
    int mBC;
    void Init();
};

extern "C" void func_001CF6C0(Comp_001CED40* self);

void Comp_001CED40::Init()
{
    mB8 = func_00185578(mC, 0xE47F1B79);
    mBC = func_00185578(mC, 0x07713C7B);
    func_001CF6C0(this);
}
