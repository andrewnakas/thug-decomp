extern "C" int func_0025C228(void* p);

struct Obj_0025ED10 {
    char pad[0x3C];
    void* m3C;
    int Fn();
};

int Obj_0025ED10::Fn()
{
    int r = 0;
    if (m3C) r = func_0025C228(m3C);
    return r;
}
