struct Tex_00139C18 {
    int m0;
    unsigned short m4;
};

extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" int func_00132580();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00105520(const char* s);
extern "C" Tex_00139C18* func_00139D70(int key);
extern "C" Tex_00139C18* func_00149FA8(char* path, int a1, int a2, int a3, int t0);
extern "C" void func_0013AA58(void* table, int* key, Tex_00139C18* t);
extern char D_003C38C0[];
extern char D_0038A050[];

extern "C" Tex_00139C18* func_00139C18(const char* name, int a1, int index, int a3, int t0)
{
    char buf[0x80];
    func_003331D0(buf, D_0038A050, name, func_00132580());
    func_0010BFC0(name);
    int key = func_00105520(name) + index;
    Tex_00139C18* t = func_00139D70(key);
    if (t) {
        t->m4++;
    } else {
        t = func_00149FA8(buf, a1, index, a3, t0);
        t->m0 = key;
        func_0013AA58(D_003C38C0, &key, t);
    }
    func_0010BFC8();
    return t;
}
