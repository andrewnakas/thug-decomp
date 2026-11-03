extern "C" void* func_001046B0(int);
extern "C" int func_00103F28(const char*, ...);
extern char D_0035B1D0[], D_0035B1F8[], D_0035B220[], D_0035B230[], D_0035B250[], D_0035B278[];
extern char D_0035B298[], D_0035B2C0[], D_0035B2D0[], D_0035B2F8[], D_0035B320[], D_0035B340[];
extern char D_0035B368[], D_0035B388[], D_0035B3B0[], D_0035B3C0[];
extern char D_00388A98[], D_00388AA0[], D_00388AA8[], D_00388AB0[];
extern int D_00388820;

class Region_0010B0E8 {
public:
    char pad[0x18];
    virtual ~Region_0010B0E8();
    Region_0010B0E8(int size);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Mem_0010B0E8 {
    char pad[0xE0];
    Region_0010B0E8* m_mainRegion;
    void* m_topDownHeap;
    Region_0010B0E8* m_scriptRegion;
    void* m_scriptHeap;
    void* m_debugHeap;
    void* m_bottomUpHeap;
    char padF8[0x30];
    Region_0010B0E8* m_skaterRegion[8];
    void* m_skaterHeap[8];
    Region_0010B0E8* m_geomRegion[8];
    void* m_geomHeap[8];
    char pad1A8[0x240];
    Region_0010B0E8* m_frontendRegion;
    void* m_frontendHeap;
    Region_0010B0E8* m_netRegion;
    void* m_netHeap;
    void InitHeaps();
};

extern "C" void* func_0010AF60(Mem_0010B0E8*, void*, int, const char*);

void Mem_0010B0E8::InitHeaps()
{
    if (D_00388820)
        m_mainRegion = new Region_0010B0E8(0xF4240);
    else
        m_mainRegion = new Region_0010B0E8(1100000);
    func_00103F28(D_0035B1D0, m_mainRegion);
    m_bottomUpHeap = func_0010AF60(this, m_mainRegion, -1, D_00388A98);
    func_00103F28(D_0035B1F8, m_bottomUpHeap);
    m_topDownHeap = func_0010AF60(this, m_mainRegion, 1, D_0035B220);
    func_00103F28(D_0035B230, m_topDownHeap);
    m_scriptRegion = new Region_0010B0E8(3954000);
    func_00103F28(D_0035B250, m_scriptRegion);
    m_scriptHeap = func_0010AF60(this, m_scriptRegion, 1, D_00388AA0);
    func_00103F28(D_0035B278, m_scriptHeap);
    m_frontendRegion = new Region_0010B0E8(0x14050);
    func_00103F28(D_0035B298, m_frontendRegion);
    m_frontendHeap = func_0010AF60(this, m_frontendRegion, 1, D_0035B2C0);
    func_00103F28(D_0035B2D0, m_frontendHeap);
    m_netRegion = new Region_0010B0E8(0x32000);
    func_00103F28(D_0035B2F8, m_netRegion);
    m_netHeap = func_0010AF60(this, m_netRegion, 1, D_00388AA8);
    func_00103F28(D_0035B320, m_netHeap);
    for (int i = 0; i < 1; i++) {
        m_skaterRegion[i] = new Region_0010B0E8(0x13498);
        func_00103F28(D_0035B340, m_skaterRegion[i]);
        m_skaterHeap[i] = func_0010AF60(this, m_skaterRegion[i], 1, D_00388AB0);
        func_00103F28(D_0035B368, m_skaterHeap[i]);
        m_geomRegion[i] = new Region_0010B0E8(0xA21C0);
        func_00103F28(D_0035B388, m_geomRegion[i]);
        m_geomHeap[i] = func_0010AF60(this, m_geomRegion[i], 1, D_0035B3B0);
        func_00103F28(D_0035B3C0, m_geomHeap[i]);
    }
    for (int j = 1; j < 8; j++) {
        m_skaterRegion[j] = 0;
        m_skaterHeap[j] = 0;
        m_geomRegion[j] = 0;
        m_geomHeap[j] = 0;
    }
}
