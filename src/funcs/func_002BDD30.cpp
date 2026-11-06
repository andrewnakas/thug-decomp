
extern char D_0037A570[];
extern long D_0037A580[2];
extern "C" void* memcpy(void* d, const void* s, unsigned int n);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);

struct Obj_002BDD30 {
    int Index();
    int NameCrc();
};

extern "C" int func_002BD248(Obj_002BDD30* o);

int Obj_002BDD30::NameCrc()
{
    union {
        char s[0x30];
        long n;
    } buf;
    if (func_002BD248(this))
        func_003331D0(buf.s, D_0037A570, func_002BD248(this) + 1);
    else
        memcpy(buf.s, D_0037A580, 12);
    return func_001F0D78(buf.s);
}
