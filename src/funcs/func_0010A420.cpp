extern "C" void* func_001047C0(int, void*);
extern "C" void* func_0010C158(void*, unsigned int, unsigned int);
extern "C" void* func_0010D0B0(void*, void*, int, const char*);
extern "C" int func_00103F28(const char*, ...);
extern "C" int func_0031BCA0(void*);
extern "C" void func_00100000();

extern char D_00464698[], D_004646B8[], D_00464740[];
extern char D_478C3F[], D_1FEFFF0[], D_468C30[], D_0034D280[];
extern char D_0035B038[], D_0035B048[], D_0035B058[];
extern int D_00393EB0;

struct SemaParam_0010A420 {
    int m_count;
    int m_max;
    int m_init;
    int m_waiting;
    unsigned int m_attr;
    unsigned int m_option;
};

struct Stack_0010A420 {
    int m0;
    int m4;
    int m8;
    char padC[0x8C - 0xC];
    int m8C;
    Stack_0010A420()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
        m8C = 0;
    }
};

struct Zero_0010A420 {
    int m_value;
    Zero_0010A420() { m_value = 0; }
};

struct Mem_0010A420 {
    int m0;
    void* m_cur;
    void* m_top;
    char padC[0x84 - 0xC];
    int m_84;
    int pad88;
    Zero_0010A420 m_8C;
    char pad90[0xD0 - 0x90];
    int m_D0;
    void* m_region;
    void* m_main;
    void* m_topHeap;
    char padE0[0xF8 - 0xE0];
    int m_F8;
    int padFC;
    int m_100;
    int pad104[2];
    int m_10C;
    int m_110;
    int m_114;
    char pad118[0x1A8 - 0x118];
    Stack_0010A420 m_stacks[4];
    int m_3E8[4];
    int m_3F8;
    int m_3FC;
    Mem_0010A420();
};

Mem_0010A420::Mem_0010A420()
{
    m_3FC = 0;
    m_3F8 = 0;
    m_region = func_0010C158(func_001047C0(0x1C, D_00464698),
                             (unsigned int)D_478C3F & 0xFFFFFFF0,
                             (unsigned int)D_1FEFFF0 & 0xFFFFFFF0);
    m_main = func_0010D0B0(func_001047C0(0x84, D_004646B8), m_region, -1, D_0035B038);
    void* top = func_0010D0B0(func_001047C0(0x84, D_00464740), m_region, 1, D_0035B048);
    unsigned int codeKb = (unsigned int)(D_0034D280 - (char*)func_00100000) >> 10;
    unsigned int dataKb = (unsigned int)(D_468C30 - D_0034D280) >> 10;
    m_cur = m_main;
    m_84 = 2;
    m_topHeap = top;
    m_top = top;
    func_00103F28(D_0035B058, func_00100000, D_0034D280, codeKb, D_0034D280, D_468C30, dataKb, codeKb + dataKb);
    m_D0 = 0;
    m_100 = 0;
    m_F8 = 0;
    m_10C = 0;
    m_114 = 0;
    m_110 = 0;
    SemaParam_0010A420 sp;
    sp.m_init = 1;
    sp.m_max = 10;
    D_00393EB0 = func_0031BCA0(&sp);
}
