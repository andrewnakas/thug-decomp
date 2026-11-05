struct Obj_00259C98;
extern "C" void func_00259D70(Obj_00259C98* self);

struct Ent_00259C98 {
    int m0;
    int m4;
    int m8;
    Ent_00259C98() { m4 = 0; m8 = 0; m0 = 0; }
};

struct Obj_00259C98 {
    Ent_00259C98 m[50];
    Obj_00259C98();
};

Obj_00259C98::Obj_00259C98()
{
    func_00259D70(this);
}
