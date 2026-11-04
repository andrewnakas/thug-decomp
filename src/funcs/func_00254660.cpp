struct MemMgr_00254660 {
    char m_pad[0xDC];
    void* m_heap;
};

struct Skate_00254660 {
    char m_pad[0x3AC];
    unsigned int m_gameMode;
};

extern int D_00392068;
extern Skate_00254660* D_0038FC78;
extern int D_0038E0A0;
extern MemMgr_00254660* D_00388A70;
extern int D_0038FBF8;
extern char D_003751C0[];

extern "C" int func_002A19A8(int);
extern "C" int func_00104968(int);
extern "C" void func_00113EF0(int);
extern "C" void func_001E0A88();
extern "C" void func_001DED00(int);
extern "C" void func_001DCD58(int);
extern "C" void func_0010A950(MemMgr_00254660* mgr, void* heap);
extern "C" void func_0010A9B0(MemMgr_00254660* mgr);
extern "C" void func_001F0500();
extern "C" void func_0022D770(Skate_00254660*);
extern "C" void* func_0022DD38(Skate_00254660*);
extern "C" void func_001F0370(const char* name, void* params, void* obj, int a);

struct FrontEnd_00254660 {
    char m_pad[0x1C];
    int m_1C;
    void Update(int paused);
};

void FrontEnd_00254660::Update(int paused)
{
    if (paused || func_002A19A8(D_00392068) || D_0038FC78->m_gameMode == 0x9F2BAFB7 || func_00104968(m_1C))
        func_00113EF0(1);
    else
        func_00113EF0(0);
    func_001E0A88();
    int s = D_0038E0A0;
    func_001DED00(s);
    if (!paused) {
        func_0010A950(D_00388A70, D_00388A70->m_heap);
        func_001DCD58(s);
        func_0010A9B0(D_00388A70);
    }
    func_0010A950(D_00388A70, D_00388A70->m_heap);
    func_001F0500();
    func_0022D770(D_0038FC78);
    if (D_0038FBF8) {
        D_0038FBF8 = 0;
        void* obj = func_0022DD38(D_0038FC78);
        func_001F0370(D_003751C0, 0, obj, 0);
    }
    func_0010A9B0(D_00388A70);
}
