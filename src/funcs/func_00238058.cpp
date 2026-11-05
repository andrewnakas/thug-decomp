struct Obj_00238058 {
    char pad[0x68];
    int m_68;
    void Start();
};

extern "C" void func_0023AC30(Obj_00238058* self, int v);

void Obj_00238058::Start()
{
    func_0023AC30(this, 1);
    m_68 = 3000;
}
