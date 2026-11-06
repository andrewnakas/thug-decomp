/* sym: __13Base_0014CBB8 = 0x0013F210 */
/* sym: _vt$12Snd_0014CBB8 = 0x0035F618 */
/* sym: __12Str_0014CBB8 = 0x00104008 */
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);
extern "C" int func_00170AE8(void* data, int a);
extern "C" int func_00170B68(void* data, void* out);
extern "C" int func_00149BC8(int id);
extern "C" void func_0017DA00(void* data, int size, int v, int a, int b, int c, int d);
extern "C" void func_001779E0();

class Str_0014CBB8 {
public:
    char m[0x14];
    Str_0014CBB8();
};

class Base_0014CBB8 {
public:
    int m0;
    int m4;
    char pad8[0xAC];
    int mB4;
    int mB8;
    Base_0014CBB8();
    virtual ~Base_0014CBB8();
};

class Snd_0014CBB8 : public Base_0014CBB8 {
public:
    unsigned long mC0 : 32;
    unsigned long mFlag0 : 1;
    unsigned long mFlag1 : 1;
    void* mC8;
    Str_0014CBB8 mCC;
    int mE0;
    Snd_0014CBB8(void* data, int size, void* anim, int id, int c, int mode, int d);
    virtual void V1();
    virtual ~Snd_0014CBB8();
};

extern "C" bool func_0014C9B0(Snd_0014CBB8* self, void* data);

Snd_0014CBB8::Snd_0014CBB8(void* data, int size, void* anim, int id, int c, int mode, int d)
{
    m4 = id;
    mE0 = 0;
    mFlag0 = 0;
    mFlag1 = 0;
    if (!mode && !c) {
        mFlag1 = 0;
        mC8 = func_0010BDE0(size);
        func_00331404(mC8, data, size);
        mC0 = func_00170AE8(mC8, 0);
        mB4 = func_00170B68(mC8, &mB8);
    } else {
        if (mode && anim) func_0014C9B0(this, anim);
        func_0017DA00(data, size, func_00149BC8(m4), 1, 1, c, d);
        mC0 = 0;
    }
    func_001779E0();
}
