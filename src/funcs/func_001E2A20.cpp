struct Packet_001E2A20 {
    char pad0[0x10];
    int m_id;
    int m_a;
    int m_b;
};

extern int D_0038E28C;
extern Packet_001E2A20 D_003F2F20;

extern "C" int func_0031C040(int id);
extern "C" int func_0031D2E8(int a, Packet_001E2A20* p, int size, int b, int c, int d);

void func_001E2A20(int id, int a, int b)
{
    if (D_0038E28C) {
        while (func_0031C040(D_0038E28C) >= 0) {
        }
    }
    D_003F2F20.m_id = id - 1;
    D_003F2F20.m_a = a;
    D_003F2F20.m_b = b;
    D_0038E28C = func_0031D2E8(2, &D_003F2F20, 0x20, 0, 0, 0);
}
