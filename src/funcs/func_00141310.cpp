class Obj_00141310 {
public:
    int m0[2];
    virtual ~Obj_00141310();
};

extern "C" Obj_00141310* func_00141250(int id);
extern "C" void* func_001324B0();
extern "C" void func_001410B0(void* mgr, int* id);

extern "C" void func_00141310(int id)
{
    Obj_00141310* o = func_00141250(id);
    func_001410B0(func_001324B0(), &id);
    if (o) {
        delete o;
    }
}
