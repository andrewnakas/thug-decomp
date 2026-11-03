struct Heap_0010B4F8 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_0010B4F8* D_00388A70;
extern "C" void func_0010A950(Heap_0010B4F8*, int);
extern "C" void func_0010A9B0(Heap_0010B4F8*);
extern "C" void* func_001046B0(int);
extern "C" void* func_0010C190(void*, int);
extern char D_0035B3E8[], D_0035B3F8[];

struct Mem_0010B4F8 {
    char pad[0x100];
    void* m_region;
    void* m_bottom;
    void* m_top;
    void InitDebugHeap();
    void* CreateHeap(void* region, int dir, const char* name);
};

extern "C" void* func_0010AF60(Mem_0010B4F8*, void*, int, const char*);

void Mem_0010B4F8::InitDebugHeap()
{
    if (m_region)
        return;
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    m_region = func_0010C190(func_001046B0(0x1C), 0x6DDD0);
    m_bottom = func_0010AF60(this, m_region, -1, D_0035B3E8);
    m_top = func_0010AF60(this, m_region, 1, D_0035B3F8);
    func_0010A9B0(D_00388A70);
}
