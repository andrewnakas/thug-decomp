extern char D_0035CC18[];
extern "C" int func_001E84E8(void* params, const char* name, int* out, int req);

class Elem_00125C98;
extern "C" void func_00124328(Elem_00125C98* self, void* params);

class Elem_00125C98 {
public:
    char pad0[0x1A0];
    int m_focusChild;
    void SetProps(void* params);
};

void Elem_00125C98::SetProps(void* params)
{
    func_001E84E8(params, D_0035CC18, &m_focusChild, 0);
    func_00124328(this, params);
}
