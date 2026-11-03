struct Region_00219508 {
    char pad0[0x8];
    int m_free;
};

struct Heap_00219508 {
    char pad0[0x8];
    int m_blocks;
    char pad0C[0x20 - 0xC];
    int m_used;
    char pad24[0x2C - 0x24];
    int m_frag;
    char pad30[0x34 - 0x30];
    Region_00219508* m_region;
    char pad38[0x44 - 0x38];
    char* m_name;
};

struct HeapMan_00219508 {
    char pad0[0xDC];
    Heap_00219508* m_main;
};

struct HashPool_00219508 {
    char pad0[0x8];
    int m_max_count;
    char pad0C[0x10 - 0xC];
    int m_count;
    char pad14[0x58 - 0x14];
    int m_peak;
};

extern "C" void func_001E6248();
extern "C" int func_0020AE90(char* name);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" Heap_00219508* func_0010B088(HeapMan_00219508* man);
extern "C" Heap_00219508* func_0010B0A8(HeapMan_00219508* man, Heap_00219508* heap);
extern "C" int func_0010C258(Region_00219508* region);
extern "C" void func_0020AFD8();
extern "C" int func_001DCAD8(int snd);
extern "C" char* func_001044A8(int s, int c);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00331BB8(char* s);
extern "C" bool func_00110DC8(char* name);
extern "C" void func_0020AF20(char* text);
extern "C" void func_0010BFD0(int a, int b);
extern "C" int func_0021AF00();
extern "C" int func_0021AF20();
extern "C" int func_0021AF40();
extern "C" int func_0021AF60();
extern "C" int func_0021AF80();
extern "C" int func_0021AFA0();
extern "C" int func_0021AFC0();
extern "C" int func_0021AFE0();
extern "C" int func_0021B000();
extern "C" int func_0021B020();
extern "C" int func_0021B040();
extern "C" int func_0021B060();
extern "C" int func_0021B080();
extern "C" int func_0021B0A0();
extern "C" int func_0021B0C0();
extern "C" int func_0021B0E0();
extern "C" int func_0021B100();
extern "C" int func_0021B120();
extern "C" int func_0021B140();
extern "C" int func_0021B160();
extern "C" int func_0021B180();
extern "C" HashPool_00219508* func_0010D478(int i);

extern HeapMan_00219508* D_00388A70;
extern int D_0038E0A0;
extern char D_003F5868[];
extern char D_00370F90[];
extern char D_00370FA0[];
extern char D_00370FD8[];
extern char D_00371010[];
extern char D_00371030[];
extern char D_00371060[];
extern char D_00371090[];
extern char D_003710B8[];
extern char D_003710E0[];
extern char D_00371100[];
extern char D_00371120[];
extern char D_00371150[];
extern char D_00371180[];
extern char D_003711A0[];
extern char D_003711C8[];
extern char D_003711E0[];
extern char D_003711F8[];
extern char D_00371210[];
extern char D_00371238[];
extern char D_00371260[];
extern char D_00371288[];
extern char D_003712B0[];
extern char D_003712D8[];
extern char D_00371300[];
extern char D_00371328[];
extern char D_00371350[];

bool Cmd_DumpHeaps_00219508(void* params, void* script)
{
    func_001E6248();
    HeapMan_00219508* man = D_00388A70;
    func_0020AE90(D_00370F90);
    Heap_00219508* heap;
    if (func_001E8708(params, 0xD65B9AC7)) {
        func_00103F28(D_00370FA0);
        func_00103F28(D_00370FD8);
        for (heap = func_0010B088(man); heap; heap = func_0010B0A8(man, heap)) {
            Region_00219508* region = heap->m_region;
            char* nm = heap->m_name;
            int avail = func_0010C258(region);
            func_00103F28(D_00371010, nm, heap->m_used, heap->m_frag, avail, region->m_free, heap->m_blocks);
        }
    } else {
        func_00103F28(D_00371030);
        func_00103F28(D_00371060);
        for (heap = func_0010B088(man); heap; heap = func_0010B0A8(man, heap)) {
            char* fmt = D_00371090;
            int used = heap->m_used / 1024;
            int frag = heap->m_frag / 1024;
            Region_00219508* region = heap->m_region;
            char* nm = heap->m_name;
            int avail = func_0010C258(region) / 1024;
            func_00103F28(fmt, nm, used, frag, avail, region->m_free / 1024, heap->m_blocks);
        }
    }
    func_0020AFD8();
    int snd = D_0038E0A0;
    func_00103F28(D_003710B8, func_001DCAD8(snd) / 1024, func_001DCAD8(snd));
    char line[0x200];
    char name[0x100];
    int i = 0;
    while (true) {
        func_003331D0(name, D_003710E0, D_003F5868, i,
                      func_001044A8(func_0010C258(man->m_main->m_region), 0x2C));
        func_00103F28(D_00371100, name, func_00331BB8(name));
        if (!func_00110DC8(name)) {
            break;
        }
        i++;
    }
    if (func_0020AE90(name)) {
        func_003331D0(line, D_00371120);
        func_0020AF20(line);
        func_003331D0(line, D_00371150);
        func_0020AF20(line);
        for (heap = func_0010B088(man); heap; heap = func_0010B0A8(man, heap)) {
            char* fmt = D_00371180;
            int used = heap->m_used / 1024;
            int frag = heap->m_frag / 1024;
            Region_00219508* region = heap->m_region;
            char* nm = heap->m_name;
            int avail = func_0010C258(region) / 1024;
            func_003331D0(line, fmt, nm, used, frag, avail, heap->m_blocks);
            func_0020AF20(line);
        }
        func_003331D0(line, D_003711A0, func_001DCAD8(snd) / 1024, func_001DCAD8(snd));
        func_0020AF20(line);
        func_003331D0(line, D_003711C8);
        func_0020AF20(line);
        func_0010BFD0(3, 0);
        func_003331D0(line, D_003711E0);
        func_0020AF20(line);
        func_0010BFD0(100, 0);
        func_0020AFD8();
    }
    func_00103F28(D_003711F8);
    func_00103F28(D_00371210, func_0021AF00(), func_0021AF20(), func_0021AF40());
    func_00103F28(D_00371238, func_0021AF60(), func_0021AF80(), func_0021AFA0());
    func_00103F28(D_00371260, func_0021AFC0(), func_0021AFE0(), func_0021B000());
    func_00103F28(D_00371288, func_0021B020(), func_0021B040(), func_0021B060());
    func_00103F28(D_003712B0, func_0021B080(), func_0021B0A0(), func_0021B0C0());
    func_00103F28(D_003712D8, func_0021B0E0(), func_0021B100(), func_0021B120());
    func_00103F28(D_00371300, func_0021B140(), func_0021B160(), func_0021B180());
    HashPool_00219508* pool = func_0010D478(0);
    func_00103F28(D_00371328, pool->m_count, pool->m_max_count, pool->m_peak);
    func_00103F28(D_00371350);
    return true;
}
