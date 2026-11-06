class Obj_00141390 {
public:
    int m0;
    int m4;
    virtual ~Obj_00141390();
};

class Cam_00141390 : public Obj_00141390 {
public:
    char padC[0x1E4];
    int m1F0;
};

extern "C" void* func_001324B0();
extern "C" void func_00141410(void* mgr);
extern "C" Cam_00141390* func_00141420(void* mgr, int a);

extern "C" void func_00141390()
{
    if (!func_001324B0())
        return;
    func_00141410(func_001324B0());
    Cam_00141390* c;
    while ((c = func_00141420(func_001324B0(), 0)) != 0) {
        if (!c->m1F0)
            delete c;
    }
}
