struct Obj_00257B00;
extern "C" void func_00257978(Obj_00257B00* self, char* buf, int a);
extern "C" void func_00257E68(Obj_00257B00* self, int a, int b, char* buf);

struct Obj_00257B00 {
    void Fn(int a, int b);
};

void Obj_00257B00::Fn(int a, int b)
{
    char buf[0xA0];
    func_00257978(this, buf, a);
    func_00257E68(this, a, b, buf);
}
