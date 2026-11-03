struct Task_00113D48 {
    char pad[0x18];
    void* m_vt;
    void* m_func;
    void* m_data;
    void Init(void* f, void* d);
};

struct Mgr_00113D48 {
    char pad[0xA0];
    char m_list[1];
};

extern int D_0038881C;
extern Mgr_00113D48* D_0038C308;
extern char D_0035C100[];
extern char D_0035C110[];
extern char D_0035C128[];
extern char D_0035C1F8[];
extern int D_00393ED0;
extern int D_00388A70;
extern unsigned char* D_00388F24;
extern Task_00113D48* D_00393ED8;

extern "C" const char* func_00106818();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00320138(const char* path, int argLen, const char* args);
extern "C" int func_00318AA8(int* count);
extern "C" unsigned char* func_0010A638(int heap, int size, int, int);
extern "C" Task_00113D48* func_001046B0(int size);
extern "C" Task_00113D48* func_001047F8(Task_00113D48* t, int);
extern "C" void func_00105260(void* list, Task_00113D48* t);
extern "C" void func_00113BB8();

inline void Task_00113D48::Init(void* f, void* d)
{
    func_001047F8(this, 0);
    m_func = f;
    m_data = d;
    m_vt = D_0035C1F8;
}

extern "C" int func_00113D48()
{
    char path[0x80];
    int ctx;
    const char* args = D_0035C100;
    Mgr_00113D48* mgr = D_0038C308;
    int r;
    if (D_0038881C) {
        func_003331D0(path, D_0035C110, func_00106818());
        r = func_00320138(path, 0x11, args);
    } else {
        r = func_00320138(D_0035C128, 0x11, args);
    }
    if (r < 0) {
        return -1;
    }
    if (func_00318AA8(&D_00393ED0) == -1) {
        return -1;
    }
    D_00388F24 = func_0010A638(D_00388A70, D_00393ED0, 1, 0);
    for (int i = 0; i < D_00393ED0; i++) {
        D_00388F24[i] = 0;
    }
    Task_00113D48* task = func_001046B0(0x24);
    task->Init((void*)func_00113BB8, &ctx);
    D_00393ED8 = task;
    func_00105260(mgr->m_list, task);
    return 0;
}
