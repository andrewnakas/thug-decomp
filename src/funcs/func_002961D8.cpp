extern "C" void* func_00185578(void* o, unsigned int type);

struct Obj_002961D8 {
    char pad[0xC];
    void* mC;
    char pad10[0xA5B4];
    void* mA5C4;
    void* mA5C8;
    void GetComps();
};

void Obj_002961D8::GetComps()
{
    mA5C4 = func_00185578(mC, 0x27D7CD28);
    mA5C8 = func_00185578(mC, 0xAC8946E2);
}
