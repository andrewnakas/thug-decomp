/* fuzzy: 86.5 */
/* NM 10/37: ThreadParam stores - game loads 0x800 into $a0 first and stores stackSize first; all 120 store orders tried (work/perm5.py) */
extern "C" void func_001F83C8();
extern char D_001F8430[];
extern char D_003F3770[];
extern char D_0038F3F0[];

struct SemaParam_001F8450 {
    int count;
    int max;
    int init;
    int waits;
    unsigned int attr;
    unsigned int option;
};

struct ThreadParam_001F8450 {
    int status;
    void (*entry)();
    void* stack;
    int stackSize;
    void* gp;
    int prio;
    int currentPrio;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
};

extern "C" int func_0031BCA0(SemaParam_001F8450*);
extern "C" int func_0031BAA0(ThreadParam_001F8450*);
extern "C" void func_0031BAC0(int, int);
extern "C" void func_00327FD0(char*, int);

void func_001F8450()
{
    ThreadParam_001F8450 tp;
    SemaParam_001F8450 sp;
    sp.max = 1;
    sp.init = 0;
    sp.option = 0;
    int sema = func_0031BCA0(&sp);
    tp.prio = 1;
    tp.entry = func_001F83C8;
    tp.stack = D_003F3770;
    tp.gp = D_0038F3F0;
    tp.stackSize = 0x800;
    func_0031BAC0(func_0031BAA0(&tp), sema);
    func_00327FD0(D_001F8430, sema);
}
