struct Obj_00211710;
struct Arg_00211710 { char pad[0xBC]; int mBC; };
extern void* D_00392068;
extern void* D_0038FC78;
extern int D_0038A0E8;
extern "C" int func_002A1998(void* p);
extern "C" int func_002A19A8(void* p);
extern "C" int func_00229DF0(Obj_00211710* self);
extern "C" int func_0022EEC0(void* p, int v);
extern "C" int func_0022DE70(void* p, int v);
extern "C" int func_00211410(Obj_00211710* self);
extern "C" int func_00211478(Obj_00211710* self, Arg_00211710* a);
extern "C" int func_00213DF8(Obj_00211710* self, int a, int b);
extern "C" int func_00214250(Obj_00211710* self, int a);
extern "C" int func_00214360(Obj_00211710* self);
extern "C" int func_00214040(Obj_00211710* self);

struct Obj_00211710 {
    int m0;
    int Run(unsigned int type, Arg_00211710* a, int b);
};

int Obj_00211710::Run(unsigned int type, Arg_00211710* a, int b)
{
    void* s = D_00392068;
    void* g = D_0038FC78;
    if (func_002A1998(s)) {
        if (func_0022EEC0(g, func_00229DF0(this))) {
            return 0;
        }
    }
    int flag = 0;
    if (a->mBC) {
        if (!func_002A19A8(s) && D_0038A0E8 == 2) {
            flag = a->mBC == func_0022DE70(g, 1);
        }
    }
    switch (type) {
    case 0:
        return func_00211410(this);
    case 1:
        return func_00211478(this, a);
    case 2:
        return func_00213DF8(this, 0, flag);
    case 3:
        return func_00213DF8(this, 1, flag);
    case 6:
        return func_00214250(this, b);
    case 4:
        func_00213DF8(this, 0, flag);
        return func_00214360(this);
    case 5:
        return func_00214040(this);
    }
    return 0;
}
