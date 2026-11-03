extern "C" void* func_002A52F0(void* table, unsigned short id);
extern "C" void func_002B2790(void* obj, int v);

struct Msg_002AD3D8 {
    signed char* mData;
    char pad4[0x1C - 0x4];
    void* m1C;
    int Handle();
};

int Msg_002AD3D8::Handle() {
    signed char* d = mData;
    void* obj = func_002A52F0(m1C, d[0]);
    if (obj) {
        func_002B2790(obj, d[1]);
    }
    return 1;
}
