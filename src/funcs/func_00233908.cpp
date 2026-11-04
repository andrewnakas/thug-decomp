extern char D_0038FD98[];
extern char D_0038FDA0[];
extern char D_00373100[];
extern char D_00373110[];
extern char D_00373130[];
extern char D_00373150[];
extern void* D_00392068;

struct Game_00233908 {
    char pad[0x3AC];
    unsigned int m_level;
};

extern Game_00233908* D_0038FC78;

struct Msg_00233908 {
    int pad0;
    unsigned char m_id;
};

extern "C" void func_001F03D0();
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, unsigned int value);
extern "C" void func_001F0370(char* name, void* params, void* a, int b);
extern "C" void func_002A3510(void* net);
extern "C" void func_002A8250(void* net, int a);
extern "C" void func_002A58F8(void* net);
extern "C" void func_002A3870(void* net);
extern "C" void func_001E6AE8(void* p, int flags);

int func_00233908(Msg_00233908* msg)
{
    void* net = D_00392068;
    Game_00233908* game = D_0038FC78;
    func_001F03D0();
    void* p = func_001E6978(func_001190D0(8));
    func_001E7A68(p, func_001F0D78(D_0038FD98), 1, 300);
    unsigned int name = func_001F0D78(D_0038FDA0);
    func_001E7A68(p, name, 0xD, func_001F0D78(D_00373100));
    if (msg->m_id == 0x51)
        func_001F0370(D_00373110, 0, 0, 0);
    else if (msg->m_id == 0x56)
        func_001F0370(D_00373130, 0, 0, 0);
    if (game->m_level == func_001F0D78(D_00373150)) {
        func_002A3510(net);
        func_002A8250(net, 9);
    } else {
        func_002A58F8(net);
        func_002A3870(net);
    }
    if (p)
        func_001E6AE8(p, 3);
    return 2;
}
