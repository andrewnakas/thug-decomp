extern "C" int func_00103F28(const char*, ...);
extern char D_0035B4D0[], D_0035B4F0[];

class Region_0010B8E0 {
public:
    char pad[0x18];
    virtual ~Region_0010B8E0();
};

struct Mem_0010B8E0 {
    char pad[0x128];
    Region_0010B8E0* m_skaterRegion[8];
    void* m_skaterHeap[8];
    Region_0010B8E0* m_geomRegion[8];
    void* m_geomHeap[8];
    void FreeSkaterHeaps();
};

extern "C" void func_0010AFE0(Mem_0010B8E0*, void*);

void Mem_0010B8E0::FreeSkaterHeaps()
{
    for (int i = 1; i < 8; i++) {
        if (m_skaterRegion[i]) {
            func_00103F28(D_0035B4D0, i);
            func_0010AFE0(this, m_skaterHeap[i]);
            delete m_skaterRegion[i];
            m_skaterHeap[i] = 0;
            m_skaterRegion[i] = 0;
        }
        if (m_geomRegion[i]) {
            func_00103F28(D_0035B4F0, i);
            func_0010AFE0(this, m_geomHeap[i]);
            delete m_geomRegion[i];
            m_geomHeap[i] = 0;
            m_geomRegion[i] = 0;
        }
    }
}
