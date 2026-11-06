struct Obj_0025BE18;
extern "C" void func_0025B538(Obj_0025BE18* self, int a);
extern "C" void func_0025B638(Obj_0025BE18* self);
extern "C" int func_0025AB78(Obj_0025BE18* self, unsigned int name, int a);

struct Obj_0025BE18 {
    int Fn(unsigned int name, int a);
};

int Obj_0025BE18::Fn(unsigned int name, int a)
{
    switch (name) {
    case 0xA8D5A188:
        func_0025B538(this, a);
        return 1;
    case 0xD7241A6C:
        func_0025B638(this);
        return 1;
    }
    return func_0025AB78(this, name, a);
}
