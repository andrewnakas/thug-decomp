struct Obj_0024F418;
extern void* D_00392068;
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" unsigned int func_0024F938(Obj_0024F418* self);
extern "C" void func_002A1C50(void* net, int a);

struct Obj_0024F418 {
    int m0;
    char m_params[4];
    void Fn(int v);
};

void Obj_0024F418::Fn(int v)
{
    void* net = D_00392068;
    func_001E7200(m_params, 0x2EBE6CD1, v);
    if (func_0024F938(this) == 0x1C471C60) func_002A1C50(net, v);
}
