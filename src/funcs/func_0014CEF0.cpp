/* sym: _$_13Base_0014CEF0 = 0x0013F258 */
/* sym: _vt$12Snd_0014CEF0 = 0x0035F618 */
/* sym: _$_12Str_0014CEF0 = 0x001040A8 */
/* sym: GetString__C12Str_0014CEF0 = 0x001041B8 */
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00170BF0(int h);
extern "C" void func_0010DCD0(const char* name);
extern "C" void func_0010BEB8(void* p);
extern "C" int func_00149BC8(int id);
extern "C" void func_0017DAA0(int v);
extern void* D_00388A70;

class Str_0014CEF0 {
public:
    char m[0x10];
    ~Str_0014CEF0();
    const char* GetString() const;
};

class Base_0014CEF0 {
public:
    int m0;
    int m4;
    char pad8[0xAC];
    int mB4;
    int mB8;
    virtual ~Base_0014CEF0();
};

class Snd_0014CEF0 : public Base_0014CEF0 {
public:
    unsigned long mC0 : 32;
    unsigned long mFlag0 : 1;
    unsigned long mFlag1 : 1;
    void* mC8;
    Str_0014CEF0 mCC;
    void* mDC;
    int mE0;
    bool IsOwned() const { return mFlag1; }
    virtual void V1();
    virtual ~Snd_0014CEF0();
};

Snd_0014CEF0::~Snd_0014CEF0()
{
    if (mC0) {
        func_00170BF0(mC0);
        if (IsOwned()) func_0010DCD0(mCC.GetString());
        if (mC8) {
            func_0010BEB8(mC8);
            mC8 = 0;
        }
    } else {
        func_0017DAA0(func_00149BC8(m4));
    }
    if (mDC) func_0010A8D8(D_00388A70, mDC);
}
