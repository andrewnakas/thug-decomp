struct Obj_00252B38;
extern "C" void func_002521A0(Obj_00252B38* self);

struct Obj_00252B38 {
    char pad[0x434];
    int m434;
    int Fn();
};

int Obj_00252B38::Fn()
{
    func_002521A0(this);
    return m434;
}
