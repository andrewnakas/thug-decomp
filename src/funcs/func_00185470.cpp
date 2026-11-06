extern "C" int func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int key);
extern "C" void func_00183E90(void* obj, int value);
extern "C" void func_00229FF8(void* params, void* out);
extern "C" void func_0022A0C0(void* params, void* out);

class Obj_00185470 {
public:
    char pad0[0xC];
    unsigned int m_flags;
    char pad10[0x40];
    char m50[0x20];
    char m70[0x10];

    void Init(void* params);
};

void Obj_00185470::Init(void* params)
{
    int v;
    if (func_001E8398(params, 0xA1DC81F9, &v, 0)) {
        func_00183E90(this, v);
    }
    func_00229FF8(params, m50);
    func_0022A0C0(params, m70);
    if (func_001E8708(params, 0x23627FD7)) {
        m_flags |= 2;
    }
}
