extern char D_00392108[];
extern char D_00378318[];
extern char D_00378328[];
extern char D_00378338[];
extern char D_00378348[];
extern char D_00378358[];
extern char D_00378368[];
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001E7A68(void* s, int name, int type, int v);
extern "C" void* func_002A6070(void* o);
extern "C" void func_00203068(void* p, int name, void* s);

struct Obj_002A2148 {
    void Set(int level);
};

void Obj_002A2148::Set(int level)
{
    char a[32];
    char b[32];
    func_003331D0(a, D_00392108, level);
    int crc = func_001F0D78(a);
    if (level == 0)
        func_003331D0(b, D_00378348);
    else if (level == 1)
        func_003331D0(b, D_00378358);
    else
        func_003331D0(b, D_00378368, level);
    void* s = func_001E6978(func_001190D0(8));
    func_001E7A30(s, func_001F0D78(D_00378318), 3, b);
    func_001E7A68(s, func_001F0D78(D_00378328), 13, crc);
    func_00203068(func_002A6070(this), func_001F0D78(D_00378338), s);
}
