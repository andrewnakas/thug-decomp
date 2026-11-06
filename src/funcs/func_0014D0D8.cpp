/* sym: _$_12Buf_0014D0D8 = 0x0013C280 */
/* sym: _vt$12Ent_0014D0D8 = 0x0035F640 */
/* sym: _$_12Ins_0014D0D8 = 0x001725B0 */
class Ins_0014D0D8 {
public:
    int m0;
    ~Ins_0014D0D8();
};

class Buf_0014D0D8 {
public:
    int m0;
    int m4;
    int m8;
    void* mC;
    int m10;
    virtual ~Buf_0014D0D8();
    virtual void V1();
};

extern "C" void func_00170DB0(void* p);
extern "C" void func_00170F58(void* p, int a);

class Ent_0014D0D8 : public Buf_0014D0D8 {
public:
    Ins_0014D0D8* m18;
    int m1C;
    void* m20;
    virtual void V1();
    virtual ~Ent_0014D0D8();
};

Ent_0014D0D8::~Ent_0014D0D8()
{
    if (m18) {
        delete m18;
        m18 = 0;
    }
    if (m20) {
        if (m4 == 1)
            func_00170DB0(m20);
        else if (m4 == 2)
            func_00170F58(m20, 1);
        m20 = 0;
    }
}
