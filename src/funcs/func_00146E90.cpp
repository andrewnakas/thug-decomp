/* sym: _$_13Base_00146E90 = 0x001385E0 */
/* sym: _$_13Wave_00146E90 = 0x0017E0B0 */
/* sym: _vt$12Snd_00146E90 = 0x0035F198 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Wave_00146E90 {
    int m0;
    ~Wave_00146E90();
};

class Base_00146E90 {
public:
    int m0;
    int m4;
    virtual ~Base_00146E90();
};

class Snd_00146E90 : public Base_00146E90 {
public:
    short mC;
    short mE;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Wave_00146E90* m1C;
    int m20;
    void* m24;
    void* m28;
    Wave_00146E90* m2C;
    virtual ~Snd_00146E90() = 0;
    virtual void V1();
};

Snd_00146E90::~Snd_00146E90()
{
    delete m1C;
    if (m24)
        func_0010A8D8(D_00388A70, m24);
    if (m28)
        func_0010A8D8(D_00388A70, m28);
    delete m2C;
}
