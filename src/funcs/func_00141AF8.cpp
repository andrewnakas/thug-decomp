/* sym: _vt$12Obj_00141AF8 = 0x0035ED80 */
extern "C" void func_00141910(void* self);
extern "C" void func_001022D8(void* p);

struct Obj_00141AF8 {
    char m_data[0x160];
    char m_160[0x30];
    Obj_00141AF8();
    virtual void Update();
};

Obj_00141AF8::Obj_00141AF8()
{
    func_00141910(this);
    func_001022D8(m_160);
}
