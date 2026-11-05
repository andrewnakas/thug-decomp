struct Obj_0025A2E8;
extern "C" void func_0025A370(Obj_0025A2E8* self);

struct Ent_0025A2E8 {
    float x, y, z, w;
    Ent_0025A2E8() {}
};

struct Obj_0025A2E8 {
    Ent_0025A2E8 m[64];
    Obj_0025A2E8();
};

Obj_0025A2E8::Obj_0025A2E8()
{
    func_0025A370(this);
}
