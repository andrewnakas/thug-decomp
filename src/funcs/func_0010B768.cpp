extern "C" void* func_001046B0(int);
extern "C" int func_00103F28(const char*, ...);
extern char D_0035B410[], D_0035B428[], D_00388AC8[], D_0035B458[], D_0035B480[], D_0035B490[], D_0035B4B8[];

class Region_0010B768 {
public:
    char pad[0x18];
    virtual ~Region_0010B768();
    Region_0010B768(int size);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Mem_0010B768 {
    char pad[0x128];
    Region_0010B768* m_skaterRegion[8];
    void* m_skaterHeap[8];
    Region_0010B768* m_geomRegion[8];
    void* m_geomHeap[8];
    void InitSkaterHeaps(int n);
};

extern "C" void* func_0010AF60(Mem_0010B768*, void*, int, const char*);

void Mem_0010B768::InitSkaterHeaps(int n)
{
    func_00103F28(D_0035B410);
    if (n >= 9)
        n = 8;
    for (int i = 1; i < n; i++) {
        m_skaterRegion[i] = new Region_0010B768(0x13498);
        func_00103F28(D_0035B428, m_skaterRegion[i]);
        m_skaterHeap[i] = func_0010AF60(this, m_skaterRegion[i], 1, D_00388AC8);
        func_00103F28(D_0035B458, m_skaterHeap[i]);
        m_geomRegion[i] = new Region_0010B768(0xA21C0);
        func_00103F28(D_0035B428, m_geomRegion[i]);
        m_geomHeap[i] = func_0010AF60(this, m_geomRegion[i], 1, D_0035B480);
        func_00103F28(D_0035B490, m_geomHeap[i]);
    }
    func_00103F28(D_0035B4B8);
}
