class Menu_0014AE08 {
public:
    char pad[0x18];
    virtual ~Menu_0014AE08();
};

extern "C" void func_0014AEE8(Menu_0014AE08* m);

extern "C" int func_0014AE08(Menu_0014AE08* m)
{
    func_0014AEE8(m);
    delete m;
    return 1;
}
