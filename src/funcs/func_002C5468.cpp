extern void* D_0038C7B0;
extern char D_0037A890[];
extern char D_0037A8A0[];
extern char D_0037A8B8[];
extern char D_0037A8D0[];
extern char D_0037A8E8[];
extern char D_0037A900[];
extern "C" int func_001F0D78(char* s);
extern "C" void func_00189750(void* p, int a, int b, unsigned int c, int d, int e);
extern "C" void func_002C9090(void* p, int d);
extern "C" void func_002C9000(void* p, int d);
extern "C" void func_002C6B08(void* p);

struct Obj_002C5468 {
    char pad0[0x60];
    unsigned int m60;
    char pad64[0x3C];
    void* mA0;
    void HandleInput();
};

void Obj_002C5468::HandleInput()
{
    if (m60 & 0x200) {
        func_002C9090(mA0, -1);
        func_002C6B08(this);
        {
            void* snd = D_0038C7B0;
            int x = func_001F0D78(D_0037A890);
            func_00189750(snd, x, func_001F0D78(D_0037A8A0), 0x36B2EE74, 0, 0);
        }
    }
    if (m60 & 0x400) {
        func_002C9090(mA0, 1);
        func_002C6B08(this);
        {
            void* snd = D_0038C7B0;
            int x = func_001F0D78(D_0037A8B8);
            func_00189750(snd, x, func_001F0D78(D_0037A8A0), 0x36B2EE74, 0, 0);
        }
    }
    if (m60 & 0x8) {
        func_002C9000(mA0, -1);
        func_002C6B08(this);
        {
            void* snd = D_0038C7B0;
            int x = func_001F0D78(D_0037A8D0);
            func_00189750(snd, x, func_001F0D78(D_0037A8E8), 0x36B2EE74, 0, 0);
        }
    }
    if (m60 & 0x10) {
        func_002C9000(mA0, 1);
        func_002C6B08(this);
        {
            void* snd = D_0038C7B0;
            int x = func_001F0D78(D_0037A900);
            func_00189750(snd, x, func_001F0D78(D_0037A8E8), 0x36B2EE74, 0, 0);
        }
    }
}
