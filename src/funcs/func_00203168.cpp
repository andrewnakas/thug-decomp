extern "C" bool func_001E89F0(void* s, unsigned int name, void** out, int required);
extern "C" bool func_001E8890(void* s, const char* name, const char** out, int required);
extern "C" bool func_001E7E58(void* s, const char* name, int* out, int required);
extern "C" bool func_001E8870(void* s, unsigned int name, const char** out, int required);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_00331BB8(const char* s);

extern char D_00366CF8[];
extern char D_0038ECA8[];
extern char D_0038EC88[];

struct Menu_00203168 {
    int m0;
    char m_params[4];
    bool GetText(int index, unsigned int name, bool hidden);
};

bool Menu_00203168::GetText(int index, unsigned int name, bool hidden)
{
    char buf[0x100];
    void* item = 0;
    func_001E89F0(m_params, name, &item, 1);
    const char* text = 0;
    int number = 0;
    if (func_001E8890(item, D_00366CF8, &text, 0)) {
        func_00331A9C(buf, text);
    } else if (func_001E7E58(item, D_0038ECA8, &number, 0)) {
        func_003331D0(buf, D_0038EC88, number);
    } else if (func_001E8870(item, 0, &text, 1)) {
        func_00331A9C(buf, text);
    }
    if (hidden) {
        for (unsigned int i = 0; i < func_00331BB8(buf); i++) {
            buf[i] = '*';
        }
    }
    return true;
}
