/* sym: __13Base_0018B908 = 0x00184DC0 */
/* sym: _vt$13Comp_0018B908 = 0x00361E18 */

extern "C" void* func_00132100();
extern "C" void func_0018DCB0(void* p);

struct Vec_0018B908 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Base_0018B908 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_0018B908();
    virtual ~Base_0018B908();
};

struct Comp_0018B908 : Base_0018B908 {
    char pad1C[0x14];
    Vec_0018B908 m30;
    char m40[0xAC];
    char mEC[0xAC];
    char m198[0xAC];
    char pad244[0xC];
    Vec_0018B908 m250;
    void* m260;
    char pad264[0x1C];
    int m280;
    char pad284[8];
    int m28C;
    Comp_0018B908();
    virtual void Update();
    virtual ~Comp_0018B908();
};

Comp_0018B908::Comp_0018B908()
{
    m_type = 0x286A8D26;
    m260 = func_00132100();
    m30.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_0018DCB0(m40);
    func_0018DCB0(mEC);
    func_0018DCB0(m198);
    m280 = 0;
    m28C = 0;
    m250.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
