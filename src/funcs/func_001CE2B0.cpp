extern "C" int func_00185578(int obj, unsigned int checksum);

struct Comp_001CE2B0 {
    char pad[0xC];
    int mC;
    char pad2[0x48 - 0x10];
    int m48;
    void Init();
};

void Comp_001CE2B0::Init()
{
    m48 = func_00185578(mC, 0x27D7CD28);
}
