/* fuzzy: 99.0 */
typedef int qword __attribute__((mode(TI)));

/* A stack holder for a reference-counted singleton: Create(1) on entry,
   Release() on exit; the holder's vtable is stored by both ctor and dtor. */
template <class T, char* VT>
struct SingletonPtr_00206F68 {
    int m_unk[2]; /* never touched here; the stack offsets put m_ptr at +8 */
    T* m_ptr;
    char* m_vt;
    SingletonPtr_00206F68()
    {
        m_vt = VT;
        m_ptr = T::Create(1);
    }
    ~SingletonPtr_00206F68()
    {
        m_vt = VT;
        T::Release();
    }
    T* operator->() { return m_ptr; }
    T* Get() { return m_ptr; }
};

struct Mtx_00206F68 {
    qword m[4];
};

struct Game_00206F68;
struct TaskMgr_00206F68;

class Dev_00206F68 {
public:
    char m_pad[0x80];
    virtual int BeginFrame();
    virtual int EndFrame();
};

struct Heap_00206F68 {
    char m_pad[0xDC];
    Dev_00206F68* mDC;
};

extern Heap_00206F68* D_00388A70;
extern int D_00388818;
extern int D_0038881C;
extern int D_00388820;
extern int D_00388824;
extern float D_00388828;
extern int D_0038ED7C;
extern int D_0038ED80;
extern int D_0038ED84;
extern int D_0038ED88;
extern char D_0038ED90[];
extern char D_0038ED98[];
extern char D_00366FA8[];
extern char D_00366FD8[];
extern char D_00366FF8[];
extern char D_00367008[];
extern char D_00367020[];
extern char D_00367040[];
extern char D_00367058[];
extern char D_00367068[];
extern char D_00367078[];
extern char D_00367088[];
extern char D_00367098[];
extern char D_003670B0[];
extern char D_003670C0[];
extern char D_003670D8[];
extern char D_003670E8[];
extern char D_00367100[];
extern char D_00367110[];
extern char D_00367138[];
extern char D_00367148[];
extern char D_00367158[];
extern char D_00367170[];
extern char D_00367188[];
extern char D_003671A0[];
extern char D_003671B8[];
extern char D_003671D0[];
extern char D_003671E8[];
extern char D_00367200[];
extern char D_00367218[];
extern char D_00367230[];
extern char D_00367248[];
extern char D_00367260[];
extern char D_00367278[];
extern char D_00367290[];
extern char D_003672A8[];
extern char D_003672C0[];
extern char D_003672D8[];
extern char D_003672F0[];
extern char D_00367308[];

extern "C" void func_0033C190();
extern "C" void func_0010BFB8(int a);
extern "C" void func_00106660(int argc, char** argv);
extern "C" void func_001651F8(int a, int b, int c, int d);
extern "C" void func_0010B0E8(Heap_00206F68* heap);
extern "C" void func_00318908(int argc, char** argv, unsigned short* a, unsigned short* b, unsigned short* c,
                              unsigned short* d, unsigned short* e, unsigned short* f, unsigned short* g,
                              unsigned short* h);
extern "C" int  func_00103F28(const char* fmt, ...);
extern "C" void func_0010BBE8();
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" int func_00331950(const char* a, const char* b);
extern "C" void func_00100000(unsigned int key);
extern "C" void func_0010A8C8(Heap_00206F68* heap, int a);
extern "C" void func_0010A8D0(Heap_00206F68* heap, int a);
extern "C" void func_001E4F50();
extern "C" void func_0010D360(int a, int b);
extern "C" void func_0010F8E0();
extern "C" void func_001109D0();
extern "C" void func_00173DF0();
extern "C" void func_00137FD0(const char* s, int a, int b);
extern "C" void func_0022A7F0();
extern "C" void func_0022A888();
extern "C" void func_00259EB8();
extern "C" void func_00105260(void* list, void* item);
extern "C" void func_00105288(void* list);
extern "C" void func_00182E38(TaskMgr_00206F68* mgr, void* task);
extern "C" void func_00182E88(TaskMgr_00206F68* mgr, void* task);
extern "C" void func_00182E60(TaskMgr_00206F68* mgr, void* task);
extern "C" void func_00182EB0(TaskMgr_00206F68* mgr);
extern "C" void func_00131840();
extern "C" void func_00182818(Game_00206F68* game);
extern "C" void func_0010F920();
extern "C" void func_00207750(Mtx_00206F68 a, Mtx_00206F68 b, Mtx_00206F68 c);


struct Mgr28_00206F68;
extern "C" Mgr28_00206F68* func_00108FC8(int create);
extern "C" void func_00109018();
struct Mgr28_00206F68 {
    static Mgr28_00206F68* Create(int create) { return func_00108FC8(create); }
    static void Release() { func_00109018(); }
};

struct Mgr38_00206F68;
extern "C" Mgr38_00206F68* func_00189118(int create);
extern "C" void func_00189168();
struct Mgr38_00206F68 {
    static Mgr38_00206F68* Create(int create) { return func_00189118(create); }
    static void Release() { func_00189168(); }
};

struct Game_00206F68;
extern "C" Game_00206F68* func_001826D0(int create);
extern "C" void func_00182720();
struct Game_00206F68 {
    char m_pad[0x8];
    char m8[0x54 - 0x8];
    char m54[0xA0 - 0x54];
    char mA0[0x10];
    static Game_00206F68* Create(int create) { return func_001826D0(create); }
    static void Release() { func_00182720(); }
};

struct TaskMgr_00206F68;
extern "C" TaskMgr_00206F68* func_00182AD8(int create);
extern "C" void func_00182B28();
struct TaskMgr_00206F68 {
    char m_pad[4];
    void* m4;
    static TaskMgr_00206F68* Create(int create) { return func_00182AD8(create); }
    static void Release() { func_00182B28(); }
};

struct Mgr68_00206F68;
extern "C" Mgr68_00206F68* func_001069E8(int create);
extern "C" void func_00106A38();
struct Mgr68_00206F68 {
    char m_pad[0x1C];
    void* m1C;
    static Mgr68_00206F68* Create(int create) { return func_001069E8(create); }
    static void Release() { func_00106A38(); }
};

struct Mgr78_00206F68;
extern "C" Mgr78_00206F68* func_00112E78(int create);
extern "C" void func_00112EC8();
struct Mgr78_00206F68 {
    static Mgr78_00206F68* Create(int create) { return func_00112E78(create); }
    static void Release() { func_00112EC8(); }
};

struct Mgr88_00206F68;
extern "C" Mgr88_00206F68* func_00183098(int create);
extern "C" void func_001830E8();
struct Mgr88_00206F68 {
    char m_pad[4];
    void* m4;
    static Mgr88_00206F68* Create(int create) { return func_00183098(create); }
    static void Release() { func_001830E8(); }
};

struct Mgr98_00206F68;
extern "C" Mgr98_00206F68* func_00114640(int create);
extern "C" void func_00114690();
struct Mgr98_00206F68 {
    static Mgr98_00206F68* Create(int create) { return func_00114640(create); }
    static void Release() { func_00114690(); }
};

struct MgrA8_00206F68;
extern "C" MgrA8_00206F68* func_0010F118(int create);
extern "C" void func_0010F168();
struct MgrA8_00206F68 {
    static MgrA8_00206F68* Create(int create) { return func_0010F118(create); }
    static void Release() { func_0010F168(); }
};

struct MgrB8_00206F68;
extern "C" MgrB8_00206F68* func_001F2BC0(int create);
extern "C" void func_001F2C10();
struct MgrB8_00206F68 {
    static MgrB8_00206F68* Create(int create) { return func_001F2BC0(create); }
    static void Release() { func_001F2C10(); }
};

struct MgrC8_00206F68;
extern "C" MgrC8_00206F68* func_001CFE38(int create);
extern "C" void func_001CFE88();
struct MgrC8_00206F68 {
    static MgrC8_00206F68* Create(int create) { return func_001CFE38(create); }
    static void Release() { func_001CFE88(); }
};

struct MgrD8_00206F68;
extern "C" MgrD8_00206F68* func_001DC4A8(int create);
extern "C" void func_001DC4F8();
struct MgrD8_00206F68 {
    static MgrD8_00206F68* Create(int create) { return func_001DC4A8(create); }
    static void Release() { func_001DC4F8(); }
};

struct MgrE8_00206F68;
extern "C" MgrE8_00206F68* func_001F8330(int create);
extern "C" void func_001F8380();
struct MgrE8_00206F68 {
    static MgrE8_00206F68* Create(int create) { return func_001F8330(create); }
    static void Release() { func_001F8380(); }
};

struct MgrF8_00206F68;
extern "C" MgrF8_00206F68* func_001863F0(int create);
extern "C" void func_00186440();
struct MgrF8_00206F68 {
    static MgrF8_00206F68* Create(int create) { return func_001863F0(create); }
    static void Release() { func_00186440(); }
};

struct Mgr108_00206F68;
extern "C" Mgr108_00206F68* func_0022C098(int create);
extern "C" void func_0022C0E8();
struct Mgr108_00206F68 {
    static Mgr108_00206F68* Create(int create) { return func_0022C098(create); }
    static void Release() { func_0022C0E8(); }
};

struct Mgr118_00206F68;
extern "C" Mgr118_00206F68* func_00253A30(int create);
extern "C" void func_00253A80();
struct Mgr118_00206F68 {
    static Mgr118_00206F68* Create(int create) { return func_00253A30(create); }
    static void Release() { func_00253A80(); }
};

struct Mgr128_00206F68;
extern "C" Mgr128_00206F68* func_0029E710(int create);
extern "C" void func_0029E760();
struct Mgr128_00206F68 {
    static Mgr128_00206F68* Create(int create) { return func_0029E710(create); }
    static void Release() { func_0029E760(); }
};

struct Mgr138_00206F68;
extern "C" Mgr138_00206F68* func_002C4970(int create);
extern "C" void func_002C49C0();
struct Mgr138_00206F68 {
    static Mgr138_00206F68* Create(int create) { return func_002C4970(create); }
    static void Release() { func_002C49C0(); }
};

struct Mgr148_00206F68;
extern "C" Mgr148_00206F68* func_0012CFA8(int create);
extern "C" void func_0012CFF8();
struct Mgr148_00206F68 {
    static Mgr148_00206F68* Create(int create) { return func_0012CFA8(create); }
    static void Release() { func_0012CFF8(); }
};

extern "C" int func_00206F68(int argc, char** argv)
{
    func_0033C190();
    func_0010BFB8(0);
    func_00106660(argc, argv);
    func_001651F8(0, 0, 0, 0);
    func_0010B0E8(D_00388A70);
    if (D_00388824) {
        unsigned short a, b, c, d, e, f, vol, sector;
        vol = 10;
        func_00318908(argc, argv, &a, &b, &c, &d, &e, &f, &vol, &sector);
        func_00103F28(D_00366FA8);
        func_00103F28(D_00366FD8, a, b, c, d, e);
        func_00103F28(D_00366FF8, f);
        func_00103F28(D_00367008, vol);
        func_00103F28(D_00367020, sector);
        D_0038ED7C = d * 60;
        D_0038ED80 = d * 60;
        D_0038ED84 = e * 60;
        if (D_00388820 && D_0038881C) {
            D_00388828 = (float)vol * 10.0f;
        }
    }
    func_00103F28(D_00367040);
    func_00103F28(D_00367058, argc);
    for (int i = 0; i < argc; i++) {
        func_00103F28(D_00367068, i, argv[i]);
    }
    func_00103F28(D_0038ED90);
    if (D_00388818) {
        func_0010BBE8();
    }
    func_0010BFC0(D_00367078);
    func_0010BFC0(D_00367088);
    if (argc == 2 && func_00331950(argv[1], D_0038ED98) == 0) {
        D_0038ED88 = 1;
    }
    func_00100000(0x6680BF3);
    while (1) {
        D_00388A70->mDC->BeginFrame();
        func_0010A8C8(D_00388A70, 0x10);
        func_001E4F50();
        func_0010BFC0(D_00367098);
        func_0010D360(0, 10000);
        func_0010BFC8();
        {
            SingletonPtr_00206F68<Mgr28_00206F68, D_00367308> s28;
            func_0010F8E0();
            func_0010BFC0(D_003670B0);
            func_001109D0();
            func_0010BFC8();
            func_0010BFC0(D_003670C0);
            SingletonPtr_00206F68<Mgr38_00206F68, D_003672F0> s38;
            SingletonPtr_00206F68<Game_00206F68, D_003672D8> game;
            SingletonPtr_00206F68<TaskMgr_00206F68, D_003672C0> mgr;
            SingletonPtr_00206F68<Mgr68_00206F68, D_003672A8> s68;
            SingletonPtr_00206F68<Mgr78_00206F68, D_00367290> s78;
            SingletonPtr_00206F68<Mgr88_00206F68, D_00367278> s88;
            SingletonPtr_00206F68<Mgr98_00206F68, D_00367260> s98;
            SingletonPtr_00206F68<MgrA8_00206F68, D_00367248> sA8;
            func_0010BFC8();
            func_00173DF0();
            func_00137FD0(D_003670D8, 0, 0);
            func_0010BFC0(D_003670E8);
            func_0022A7F0();
            func_0010BFC0(D_00367100);
            func_0010BFC8();
            func_0022A888();
            func_0010BFC8();
            func_0010BFC0(D_00367100);
            func_00259EB8();
            SingletonPtr_00206F68<MgrB8_00206F68, D_00367230> sB8;
            SingletonPtr_00206F68<MgrC8_00206F68, D_00367218> sC8;
            SingletonPtr_00206F68<MgrD8_00206F68, D_00367200> sD8;
            SingletonPtr_00206F68<MgrE8_00206F68, D_003671E8> sE8;
            SingletonPtr_00206F68<MgrF8_00206F68, D_003671D0> sF8;
            SingletonPtr_00206F68<Mgr108_00206F68, D_003671B8> s108;
            SingletonPtr_00206F68<Mgr118_00206F68, D_003671A0> s118;
            SingletonPtr_00206F68<Mgr128_00206F68, D_00367188> s128;
            SingletonPtr_00206F68<Mgr138_00206F68, D_00367170> s138;
            SingletonPtr_00206F68<Mgr148_00206F68, D_00367158> s148;
            func_0010BFC8();
            func_0010BFC0(D_00367110);
            func_00105260(game->mA0, mgr->m4);
            func_00105260(game->mA0, s68->m1C);
            func_00105260(game->m8, s88->m4);
            func_00182E38(mgr.Get(), sB8.Get());
            func_00182E38(mgr.Get(), s138.Get());
            func_00182E38(mgr.Get(), s118.Get());
            func_00182E38(mgr.Get(), s108.Get());
            func_00182E38(mgr.Get(), sA8.Get());
            func_00182E88(mgr.Get(), sB8.Get());
            func_00182E88(mgr.Get(), s118.Get());
            func_00182E88(mgr.Get(), s108.Get());
            func_00182E88(mgr.Get(), s138.Get());
            func_00182E88(mgr.Get(), sA8.Get());
            func_0010BFC8();
            func_0010BFC0(D_00367138);
            func_00131840();
            func_0010BFC8();
            func_0010BFC8();
            func_0010BFC0(D_00367148);
            func_00182818(game.Get());
            func_0010BFC8();
            func_00182EB0(mgr.Get());
            func_00182E60(mgr.Get(), s108.Get());
            func_00182E60(mgr.Get(), s118.Get());
            func_00182E60(mgr.Get(), s138.Get());
            func_00182E60(mgr.Get(), sA8.Get());
            func_00105288(game->m54);
            func_00105288(game->m8);
            func_00105288(game->mA0);
        }
        func_0010F920();
        func_0010A8D0(D_00388A70, 0x10);
        D_00388A70->mDC->EndFrame();
        Mtx_00206F68 m[3];
        func_00207750(m[0], m[1], m[2]);
    }
}
