extern "C" void* func_001046B0(int);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);

struct Owner_00119A70;

class Ev_00119A70 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual ~Ev_00119A70();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Init(void* params);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Ev_0011AC98 : public Ev_00119A70 {
public:
    char pad[0x8];
    Ev_0011AC98(Owner_00119A70* owner);
};

class Ev_0011BA68 : public Ev_00119A70 {
public:
    Ev_0011BA68(Owner_00119A70* owner);
};

class Ev_0011AFB8 : public Ev_00119A70 {
public:
    char pad[0x20];
    Ev_0011AFB8(Owner_00119A70* owner);
};

class Ev_0011CE20 : public Ev_00119A70 {
public:
    char pad[0x808];
    Ev_0011CE20(Owner_00119A70* owner);
};

class Ev_0011BB08 : public Ev_00119A70 {
public:
    Ev_0011BB08(Owner_00119A70* owner);
};

class Ev_0011B5D0 : public Ev_00119A70 {
public:
    char pad[0x8];
    Ev_0011B5D0(Owner_00119A70* owner);
};

class Ev_0011CF38 : public Ev_00119A70 {
public:
    Ev_0011CF38(Owner_00119A70* owner);
};

class Ev_0011CFC0 : public Ev_00119A70 {
public:
    char pad[0xC];
    Ev_0011CFC0(Owner_00119A70* owner);
};

extern "C" void func_00119CB0(Owner_00119A70* owner, Ev_00119A70* ev, int prio);

extern "C" Ev_00119A70* func_00119A70(Owner_00119A70* owner, void* params)
{
    unsigned int type;
    int prio;
    Ev_00119A70* ev = 0;
    func_001E8398(params, 0x7321A8D6, &type, 1);
    prio = 500;
    switch (type) {
    case 0xCB4533FF:
        ev = new Ev_0011AC98(owner);
        break;
    case 0xD079853E:
        ev = new Ev_0011BA68(owner);
        break;
    case 0x6D941203:
        ev = new Ev_0011AFB8(owner);
        break;
    case 0xCFC5B380:
        ev = new Ev_0011CE20(owner);
        break;
    case 0xFDF0436C:
        ev = new Ev_0011BB08(owner);
        break;
    case 0xDF5C091A:
        ev = new Ev_0011B5D0(owner);
        prio = 100;
        break;
    case 0x26205DB6:
        ev = new Ev_0011CF38(owner);
        break;
    case 0x659BF355:
        ev = new Ev_0011CFC0(owner);
        break;
    }
    func_001E7DE8(params, 0x9D5923D8, &prio, 0);
    ev->Init(params);
    ev->mC = prio;
    func_00119CB0(owner, ev, prio);
    return ev;
}
