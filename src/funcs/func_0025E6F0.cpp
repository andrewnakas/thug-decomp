extern "C" void func_00144D58(void* obj, float v);

struct Obj_0025E6F0 {
    char m_pad[0xC];
    void* m_obj;
    char m_pad2[0xB70 - 0x10];
    float m_value;
    void Apply();
};

void Obj_0025E6F0::Apply()
{
    func_00144D58(m_obj, m_value);
}
