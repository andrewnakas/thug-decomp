class Base_001A4700 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2(void* params);
};

class Obj_001A4700 : public Base_001A4700 {
public:
    int Fn(unsigned int key, void* params);
};

int Obj_001A4700::Fn(unsigned int key, void* params)
{
    switch (key) {
    case 0x785E57C7:
        V2(params);
        break;
    default:
        return 2;
    }
    return 1;
}
