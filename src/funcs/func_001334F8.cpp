extern "C" char* func_00331A9C(char* d, const char* s);

class Scene_001334F8 {
public:
    char pad0[0x164];
    char m_name[0x80];
    int m1E4;
    char pad1E8[0x274 - 0x1E8];
    int m_dirty;
    char pad278[0x280 - 0x278];
    virtual void V0();
    virtual void V1();
    virtual void Refresh();
    void SetName(const char* name, int flags);
};

void Scene_001334F8::SetName(const char* name, int flags)
{
    func_00331A9C(m_name, name);
    m1E4 = flags;
    m_dirty = 1;
    Refresh();
}
