extern char D_00390860[];
extern char D_00375178[];
extern char D_00375188[];
extern char D_00375198[];
extern char D_003751A8[];

extern "C" int func_00113E98(char* buf);
extern "C" void func_00113EE8();
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E7360(void* s, int name, unsigned int value);
extern "C" void func_001E7138(void* s, const char* name, const char* value);
extern "C" void func_001E7268(void* s, const char* name, int value);
extern "C" void func_001F0370(const char* name, void* params, void* obj, int a);
extern "C" void func_001E6AE8(void* s, int in_chrg);

struct Keyboard_002544F8 {
    char m_pad[0x48];
    int m_maxLength;
};

struct Task_002544F8 {
    char m_pad[0x20];
    Keyboard_002544F8* m_data;
};

void HandleKeyboard_002544F8(Task_002544F8* task)
{
    Keyboard_002544F8* kb = task->m_data;
    char buf[256];
    int n = func_00113E98(buf);
    for (int i = 0; i < n; i++) {
        unsigned char c = buf[i];
        if ((c >= ' ' && c <= '~') || (char)c == 0x19 || (char)c == 0x18) {
            void* p = func_001E6978(func_001190D0(8));
            if (buf[i] == 0x19) {
                func_001E7360(p, 0, func_001F0D78(D_00375178));
            } else if (buf[i] == 0x18) {
                func_001E7360(p, 0, func_001F0D78(D_00375188));
            } else {
                char s[2];
                s[0] = buf[i];
                s[1] = 0;
                func_001E7138(p, D_00390860, s);
            }
            func_001E7268(p, D_00375198, kb->m_maxLength);
            func_001F0370(D_003751A8, p, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
        }
    }
    func_00113EE8();
}
