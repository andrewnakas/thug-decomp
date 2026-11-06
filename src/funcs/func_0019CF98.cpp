class Base_0019CF98 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4(void* params);
};

class Obj_0019CF98 : public Base_0019CF98 {
public:
    int Fn(unsigned int key, void* params);
};

int Obj_0019CF98::Fn(unsigned int key, void* params)
{
    switch (key) {
    case 0x469FD:
        V4(params);
        V3();
        break;
    default:
        return 2;
    }
    return 1;
}
