extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* list, int v);

struct Info1B4D00 {
    char m_pad[0x24];
    int m24;
};

struct Obj1B4D00 {
    char m_pad[0xC];
    Info1B4D00* mC;
    void* MakePair(int v);
};

void* Obj1B4D00::MakePair(int v)
{
    void* list = func_001E6978(func_001190D0(8));
    func_001E6AC8(list, v);
    func_001E6AC8(list, mC->m24);
    return list;
}
