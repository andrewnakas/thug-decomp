extern "C" unsigned int func_0010FC30();
extern "C" void func_00200C68(int obj, int type, int size, void* data, int a, int b, int c);

struct Obj_002A53A0 {
    char pad0[0x20];
    int m20;
    void SendTime();
};

void Obj_002A53A0::SendTime() {
    if (m20) {
        unsigned int t = func_0010FC30();
        func_00200C68(m20, 0x11, 4, &t, -1, 0x141E, 0);
    }
}
