struct Obj_002BCDF8;
extern "C" void func_002C3330(Obj_002BCDF8* o);

struct Obj_002BCDF8 {
    int m0;
    int m4;
    void Update();
};

void Obj_002BCDF8::Update()
{
    if (m4)
        func_002C3330(this);
}
