struct Heap_002192B8 {
    char pad0[0x8];
    int m_used_blocks;
    int m_peak_used_blocks;
    char pad10[0x14 - 0x10];
    int m_frag_blocks;
    int m_peak_frag_blocks;
    char pad1C[0x20 - 0x1C];
    int m_used;
    int m_peak_used;
    char pad28[0x2C - 0x28];
    int m_frag;
    int m_peak_frag;
};

extern "C" unsigned int func_001F0D78(char* name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Heap_002192B8* func_0010ACE0(void* man, unsigned int name);
extern "C" char* func_0010AA38(void* man, unsigned int name);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_00103F28(const char* fmt, ...);

extern void* D_00388A70;
extern char D_00370F08[];
extern char D_00370F18[];
extern char D_00370F38[];
extern char D_0038F380[];
extern char D_0038F710[];

bool Cmd_HeapInfo_002192B8(void* params, void* script)
{
    void* man = D_00388A70;
    unsigned int name = func_001F0D78(D_00370F08);
    if (params) {
        func_001E8398(params, 0, &name, 0);
    }
    Heap_002192B8* heap = func_0010ACE0(man, name);
    char buf[0x40];
    func_00331A9C(buf, func_0010AA38(man, name));
    if (heap) {
        func_00103F28(D_0038F380);
        func_00103F28(D_0038F710, buf);
        func_00103F28(D_00370F18, heap->m_used / 1024, heap->m_used_blocks, heap->m_peak_used / 1024, heap->m_peak_used_blocks);
        func_00103F28(D_00370F38, heap->m_frag / 1024, heap->m_frag_blocks, heap->m_peak_frag / 1024, heap->m_peak_frag_blocks);
        func_00103F28(D_0038F380);
    }
    return true;
}
