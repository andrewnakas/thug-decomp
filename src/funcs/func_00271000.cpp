extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_00271000 {
    char pad[0xC];
    void* mC;
    char pad2[0x54 - 0x10];
    void* m54;
    void* m58;
    void* m5C;
    void* m60;
    void Init();
};

void Obj_00271000::Init()
{
    m54 = func_00185578(mC, 0x5BD63B29);
    m58 = func_00185578(mC, 0x589E5FB3);
    m5C = func_00185578(mC, 0xD9151D4D);
    m60 = func_00185578(mC, 0x726E85AA);
}
