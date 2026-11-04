extern char D_00375068[];
extern char D_00374E80[];
extern char D_00374EA0[];
extern char D_00374EB8[];
extern char D_00374ED8[];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void* func_001E5588(const char* name, int assert_);
extern "C" void* func_001E55F8(const char* name, int assert_);
extern "C" void* func_001190D0(int size);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E8E98(void* arr, int type, int size);
extern "C" void func_001E66C0(void* dst, void* src);

struct CreateATrick_00252BA0 {
    void* m_info;
    void* m_rotations;
    void* m_animations;
    void* m_vtbl;
    CreateATrick_00252BA0* Init();
};

CreateATrick_00252BA0* CreateATrick_00252BA0::Init()
{
    m_vtbl = D_00375068;
    func_00103F28(D_00374E80);
    void* info = func_001E5588(D_00374EA0, 1);
    m_info = func_001E6978(func_001190D0(8));
    func_001E6AC8(m_info, info);
    void* rot = func_001E55F8(D_00374EB8, 1);
    m_rotations = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(m_rotations, 6, 10);
    func_001E66C0(m_rotations, rot);
    void* anim = func_001E55F8(D_00374ED8, 1);
    m_animations = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(m_animations, 6, 10);
    func_001E66C0(m_animations, anim);
    return this;
}
