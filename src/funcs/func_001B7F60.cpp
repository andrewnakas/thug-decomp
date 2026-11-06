extern char D_00362E88[];

struct Inner_001B7F60 {
    int m0;
    int m4;
    virtual ~Inner_001B7F60();
};

struct Obj_001B7F60;
extern "C" void func_00184DD8(Obj_001B7F60* o, int f);

struct Obj_001B7F60 {
    char pad[0x18];
    void* m18;
    int m1C;
    Inner_001B7F60* m20;
    void Destroy(int flags);
};

void Obj_001B7F60::Destroy(int flags)
{
    m18 = D_00362E88;
    delete m20;
    func_00184DD8(this, flags);
}
