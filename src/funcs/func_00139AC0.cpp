struct Tex_00139AC0 {
    int m0;
    unsigned short m4;
};

extern "C" int func_00105520(const char* s);
extern "C" Tex_00139AC0* func_00139D70(int key);
extern "C" Tex_00139AC0* func_0014A0E0(int key);
extern "C" void func_0013AA58(void* table, int* key, Tex_00139AC0* t);
extern char D_003C38C0[];

extern "C" Tex_00139AC0* func_00139AC0(const char* name)
{
    int key = func_00105520(name);
    Tex_00139AC0* t = func_00139D70(key);
    if (t) {
        t->m4++;
    } else {
        t = func_0014A0E0(key);
        func_0013AA58(D_003C38C0, &key, t);
    }
    return t;
}
