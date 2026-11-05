struct Obj_001CCFE8 {
    char pad[0xC];
    void* mC;
    char pad2[0xA4 - 0x10];
    void* mA4;
    void* mA8;
    void* mAC;
    void Init();
};
extern "C" void* func_00185578(void* o, unsigned int id);

void Obj_001CCFE8::Init()
{
    mA4 = func_00185578(mC, 0x81C7122D);
    mA8 = func_00185578(mC, 0xC4E311FA);
    mAC = func_00185578(mC, 0x5E43A604);
}
