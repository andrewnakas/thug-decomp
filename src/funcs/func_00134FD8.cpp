extern "C" void func_0013C540(void* model);
extern "C" void func_0013C518(void* model, int c);

class Obj_00134FD8 {
public:
    char pad0[0x20];
    void* m_model;
    void SetColor(int c);
};

void Obj_00134FD8::SetColor(int c)
{
    if (m_model) {
        func_0013C540(m_model);
        func_0013C518(m_model, c);
    }
}
