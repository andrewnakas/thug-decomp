/* sym: _vt$11It_00215778 = 0x003714C0 */

struct It_00215778 {
    void* m_cur;
    int m_4;

    It_00215778() { m_4 = 0; }
    virtual void Reset();
    virtual ~It_00215778() {}
};

struct Item_00215778 {
    char pad0[0x20];
    unsigned int m_flags;
};

extern void* D_00392068;
extern "C" void* func_002A56E0(void* mgr);
extern "C" int func_002B1FE8(void* p);
extern "C" Item_00215778* func_002A5520(void* mgr, It_00215778* it);
extern "C" Item_00215778* func_002A5558(void* mgr, It_00215778* it);
extern "C" int func_002A18E0(void* mgr);

int func_00215778()
{
    void* mgr = D_00392068;
    It_00215778 it;
    void* p = func_002A56E0(mgr);
    if (p) return func_002B1FE8(p);
    for (Item_00215778* i = func_002A5520(mgr, &it); i; i = func_002A5558(mgr, &it)) {
        if (i->m_flags & 1) {
            if (i->m_flags & 4) return 1;
        }
    }
    return func_002A18E0(mgr) == 1;
}
