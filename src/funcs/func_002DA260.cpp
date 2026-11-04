extern "C" void* func_003315B8(void* p, int c, int n);

struct Obj_002DA260 {
    int m0;
    int m4[12];
    int m34[12];
    Obj_002DA260();
};

Obj_002DA260::Obj_002DA260()
{
    m0 = 0;
    func_003315B8(m4, 0, sizeof(m4));
    func_003315B8(m34, 0, sizeof(m34));
}
