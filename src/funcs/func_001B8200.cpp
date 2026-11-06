/* sym: __13Base_001B8200 = 0x00184DC0 */
/* sym: _vt$12Obj_001B8200 = 0x00362FD0 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" void* func_00102FD0(void* p);

struct Base_001B8200 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B8200();
    virtual ~Base_001B8200();
};

struct Obj_001B8200 : Base_001B8200 {
    char pad1C[0x2C - 0x1C];
    int m2C;
    char pad30[4];
    float m34;
    char pad38[0xE0 - 0x38];
    float mE0;
    float mE4;
    float mE8;
    float mEC;
    float mF0;
    char padF4[0x104 - 0xF4];
    float m104;
    char pad108[4];
    float m10C;
    char pad110[0x164 - 0x110];
    void* m164;
    int m168;
    int m16C;
    int m170;
    Obj_001B8200();
    virtual void Update();
};

Obj_001B8200::Obj_001B8200()
{
    m_type = 0x5E43A604;
    m2C = 0;
    m164 = func_00102FD0(func_0010A638(D_00388A70, 0xA0, 1, 0));
    m10C = 0.0625f;
    mE0 = 0.25f;
    mE4 = 0.5f;
    m104 = 1.0f;
    m34 = 1.0f;
    mE8 = 1.0f;
    mEC = 1.0f;
    mF0 = 0.1f;
    m168 = 0;
    m16C = 0;
    m170 = 0;
}
