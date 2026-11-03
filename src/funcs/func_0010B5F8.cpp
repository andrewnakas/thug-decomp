extern "C" void* func_001046B0(int);
extern "C" void* func_0010C190(void*, int);
extern char D_0035B190[], D_0035B1A8[];

struct Mem_0010B5F8 {
    char pad[0x10C];
    void* m_region;
    void* m_bottom;
    void* m_top;
    void InitRegion(int size);
};

extern "C" void* func_0010AF60(Mem_0010B5F8*, void*, int, const char*);

void Mem_0010B5F8::InitRegion(int size)
{
    if (m_region)
        return;
    m_region = func_0010C190(func_001046B0(0x1C), size);
    m_top = func_0010AF60(this, m_region, 1, D_0035B190);
    m_bottom = func_0010AF60(this, m_region, -1, D_0035B1A8);
}
