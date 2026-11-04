typedef int qword_001B11D0 __attribute__((mode(TI)));

struct Vec_001B11D0 {
    union {
        qword_001B11D0 q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Mat_001B11D0 {
    Vec_001B11D0 row[4];
    const Vec_001B11D0& operator[](int i) const { return row[i]; }
    Mat_001B11D0& operator=(const Mat_001B11D0& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
};

struct Obj_001B11D0 {
    char pad[0x80];
    Vec_001B11D0 m80;
    char pad90[0x30];
    Mat_001B11D0 mC0;
};

extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" void func_0022A090(int id, void* out);

struct C_001B11D0 {
    char pad[0xC];
    Obj_001B11D0* mC;
    char pad10[0x34];
    int m44;
    char pad48[0x8];
    char m50[0x40];
    Vec_001B11D0 m90;
    Vec_001B11D0 mA0;
    Vec_001B11D0 mB0;
    int mC0;
    float mC4;
    float mC8;
    char padCC[0x64];
    Mat_001B11D0 m130;
    void Init(void* params);
};

void C_001B11D0::Init(void* params)
{
    func_001E7DE8(params, 0xE50D6573, &m44, 1);
    func_0022A090(m44, m50);
    mC0 = 0;
    mB0 = m90 = mA0 = mC->m80;
    func_001E7EB0(params, 0x367C4A1B, &mC4, 0);
    func_001E7EB0(params, 0x86F46E7B, &mC8, 0);
    m130 = mC->mC0;
}
