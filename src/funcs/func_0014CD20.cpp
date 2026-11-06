/* sym: __13Base_0014CD20 = 0x0013F210 */
/* sym: _vt$12Snd_0014CD20 = 0x0035F618 */
/* sym: __12Str_0014CD20 = 0x00104008 */
/* sym: __as__12Str_0014CD20PCc = 0x00104110 */
/* sym: GetString__C12Str_0014CD20 = 0x001041B8 */
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" int func_003331D0(char* dst, const char* fmt, ...);
extern "C" void func_00104418(char* s);
extern "C" const char* func_00132580();
extern "C" void* func_0010DAB0(const char* name);
extern "C" int func_00170AE8(void* data, int a);
extern "C" int func_00170B68(void* data, void* out);
extern "C" int func_00149BC8(int id);
extern "C" void func_0017D978(const char* name, int v, int a, int b, int c, int d);
extern "C" void func_001779E0();

extern char D_0038AD90[];
extern char D_0038AD98[];
extern char D_0035F5F8[];
extern char D_0035F608[];

struct Cpy8_0014CD20 {
    char c[8];
};

class Str_0014CD20 {
public:
    char m[0x14];
    Str_0014CD20();
    Str_0014CD20& operator=(const char* s);
    const char* GetString() const;
};

class Base_0014CD20 {
public:
    int m0;
    int m4;
    char pad8[0xAC];
    int mB4;
    int mB8;
    Base_0014CD20();
    virtual ~Base_0014CD20();
};

class Snd_0014CD20 : public Base_0014CD20 {
public:
    unsigned long mC0 : 32;
    unsigned long mFlag0 : 1;
    unsigned long mFlag1 : 1;
    void* mC8;
    Str_0014CD20 mCC;
    int mE0;
    Snd_0014CD20(const char* name, int id, int c, int mode, int d);
    virtual void V1();
    virtual ~Snd_0014CD20();
};

extern "C" bool func_0014CA78(Snd_0014CD20* self, const char* name);

Snd_0014CD20::Snd_0014CD20(const char* name, int id, int c, int mode, int d)
{
    char anim[256];
    char path[512];
    m4 = id;
    mE0 = 0;
    mFlag1 = 0;
    if (!mode && !c) {
        func_00331A9C(path, name);
        char* p = func_003364D8(path, D_0038AD98);
        *p = 0;
        func_003331D0(p, D_0035F608, func_00132580());
        mCC = path;
        mFlag1 = 1;
        void* data = func_0010DAB0(mCC.GetString());
        mC0 = func_00170AE8(data, 0);
        mB4 = func_00170B68(data, &mB8);
    } else {
        if (mode) {
            func_00331A9C(anim, name);
            func_00104418(anim);
            char* p = func_003364D8(anim, D_0035F5F8);
            if (p) {
                *(Cpy8_0014CD20*)p = *(Cpy8_0014CD20*)D_0038AD90;
                func_0014CA78(this, anim);
            }
        }
        func_0017D978(name, func_00149BC8(m4), 1, 1, c, d);
        mC0 = 0;
    }
    func_001779E0();
}
