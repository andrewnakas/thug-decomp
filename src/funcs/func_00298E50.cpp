struct Obj_00298E50;
extern "C" float func_00298CC8(Obj_00298E50* o);

struct Obj_00298E50 {
    char pad[0x14];
    float m14;
    char pad18[0x28 - 0x18];
    float m28;
    void Update();
};

void Obj_00298E50::Update()
{
    m28 = m14 - func_00298CC8(this);
}
