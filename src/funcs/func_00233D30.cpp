extern char D_003730A0[];
extern char D_00373188[];
extern char D_003731C0[];

struct Heap_00233D30 {
    char pad[0xEC];
    void* m_EC;
};

extern Heap_00233D30* D_00388A70;

struct Msg_00233D30 {
    unsigned char* m_data;
    char pad4[0x18];
    void* m_game;
};

extern "C" void* func_0022E358(void* g);
extern "C" bool func_0024F8D8(void* a, char* name);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void* func_0022E048(void* g);
extern "C" void func_0010A950(Heap_00233D30* heap, void* a);
extern "C" void func_0010A9B0(Heap_00233D30* heap);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" unsigned int func_00266270(void* a, unsigned char b);
extern "C" void func_001E90F8(void* arr, int i, unsigned int value);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7B38(void* params, unsigned int name, void* arr);
extern "C" void func_00266328(void* a, void* params);
extern "C" void func_00266370(void* a);
extern "C" void func_001E6AE8(void* p, int flags);

int func_00233D30(Msg_00233D30* msg)
{
    char buf[32];
    void* game = msg->m_game;
    unsigned char* data = msg->m_data;
    if (!func_0024F8D8(func_0022E358(game), D_003730A0)) {
        func_00103F28(D_00373188);
        return 3;
    }
    unsigned char* p = data + 8;
    void* colors = func_0022E048(game);
    func_0010A950(D_00388A70, D_00388A70->m_EC);
    void* params = func_001E6978(func_001190D0(8));
    for (int i = 0; i < 8; i++) {
        if (data[i]) {
            void* arr = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr, data[i], 0xD);
            for (int j = 0; j < data[i]; j++)
                func_001E90F8(arr, j, func_00266270(colors, *p++));
            func_003331D0(buf, D_003731C0, i);
            func_001E7B38(params, func_001F0D78(buf), arr);
        }
    }
    func_00266328(colors, params);
    func_00266370(colors);
    if (params)
        func_001E6AE8(params, 3);
    func_0010A9B0(D_00388A70);
    return 1;
}
