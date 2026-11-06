struct Obj_001B6898;
extern "C" void func_001B6BC0(Obj_001B6898* o, void* p);
extern "C" void func_001B66E0(Obj_001B6898* o);

struct Owner_001B6898 {
    char pad[0x18];
    unsigned int m18;
    char pad1C[0x50 - 0x1C];
    char m50[4];
};

struct Obj_001B6898 {
    char pad[0xC];
    Owner_001B6898* mC;
    void Method();
};

void Obj_001B6898::Method()
{
    Owner_001B6898* o = mC;
    if (o->m18 >= 8)
        func_001B6BC0(this, o->m50);
    func_001B66E0(this);
}
