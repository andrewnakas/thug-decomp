struct Heap_0010DF08 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_0010DF08* D_00388A70;
extern "C" void func_0010A950(Heap_0010DF08*, int);
extern "C" void func_0010A9B0(Heap_0010DF08*);
extern "C" void func_001E7C80(void*, int, const char**, int);
extern "C" int func_001E84E8(void*, const char*, unsigned int*, int);
extern "C" void func_0010D518(const char*);
extern char D_00388C60[];

bool func_0010DF08(void* params, void* script)
{
    const char* name;
    func_001E7C80(params, 0, &name, 1);
    unsigned int heap = 0;
    func_001E84E8(params, D_00388C60, &heap, 0);
    switch (heap) {
    case 0:
        heap = 0;
        break;
    case 0x477FC6DE:
        func_0010A950(D_00388A70, D_00388A70->m_D8);
        break;
    case 0xC80BF12D:
        func_0010A950(D_00388A70, D_00388A70->m_DC);
        break;
    default:
        heap = 0;
        break;
    }
    func_0010D518(name);
    if (heap)
        func_0010A9B0(D_00388A70);
    return true;
}
