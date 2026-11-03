struct Heap_00109088 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_00109088* D_00388A70;
extern "C" void func_0010A950(Heap_00109088*, int);
extern "C" void func_0010A9B0(Heap_00109088*);
extern "C" void func_00108AB0(int, int, int, int, int);

void func_00109088(int a, int b, int c, int d, int alt)
{
    if (alt)
        func_0010A950(D_00388A70, D_00388A70->m_DC);
    else
        func_0010A950(D_00388A70, D_00388A70->m_D8);
    func_00108AB0(a, b, c, d, alt);
    func_0010A9B0(D_00388A70);
}
