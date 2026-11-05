struct Obj_0025C930;
extern "C" void* func_0010F6A8(void* p, int a, unsigned int name, int b);
extern "C" int func_0025CD00(Obj_0025C930* self, void* d);
extern "C" void func_0010F710(void* p, int a, unsigned int name);

struct Obj_0025C930 {
    int m0;
    void* m4;
    void Fn();
};

void Obj_0025C930::Fn()
{
    func_0025CD00(this, func_0010F6A8(m4, 0, 0x5AC14717, 1));
    func_0010F710(m4, 0, 0x5AC14717);
}
