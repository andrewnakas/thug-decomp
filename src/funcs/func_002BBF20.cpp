extern char D_0037A6F0[];
extern "C" void func_002BAAC0(void* p);

struct Obj_002BBF20 {
    int m0;
    int m4;
    unsigned int m8;
    char padC[0x2C];
    void* m38;
    Obj_002BBF20* Init();
};

Obj_002BBF20* Obj_002BBF20::Init() {
    func_002BAAC0(this);
    m38 = D_0037A6F0;
    m8 |= 2;
    return this;
}
