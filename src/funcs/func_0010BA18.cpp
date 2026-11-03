class Region_0010BA18 {
public:
    char pad[0x18];
    virtual ~Region_0010BA18();
};

struct Mem_0010BA18 {
    char pad[0xE0];
    Region_0010BA18* m_regionA;
    void* m_heapA;
    Region_0010BA18* m_regionB;
    void* m_heapB;
    Region_0010BA18* m_regionC;
    void* m_heapC;
    char padF8[0x128 - 0xF8];
    Region_0010BA18* m_skaterRegion[8];
    void* m_skaterHeap[8];
    Region_0010BA18* m_geomRegion[8];
    void* m_geomHeap[8];
    char pad1A8[0x3E8 - 0x1A8];
    Region_0010BA18* m_regionD;
    void* m_heapD;
    void FreeAll();
};

extern "C" void func_0010AFE0(Mem_0010BA18*, void*);
extern "C" void func_0010B8E0(Mem_0010BA18*);

void Mem_0010BA18::FreeAll()
{
    func_0010AFE0(this, m_heapA);
    delete m_regionA;
    func_0010AFE0(this, m_heapB);
    delete m_regionB;
    func_0010AFE0(this, m_heapC);
    delete m_regionC;
    func_0010AFE0(this, m_heapD);
    delete m_regionD;
    for (int i = 0; i < 1; i++) {
        func_0010AFE0(this, m_skaterHeap[i]);
        delete m_skaterRegion[i];
        func_0010AFE0(this, m_geomHeap[i]);
        delete m_geomRegion[i];
    }
    func_0010B8E0(this);
}
