class Heap_0010B680 {
public:
    char pad[0x18];
    virtual ~Heap_0010B680();
};

struct Obj_0010B680;
extern "C" void func_0010AFE0(Obj_0010B680* self, void* item);

struct Obj_0010B680 {
    char pad[0x10C];
    Heap_0010B680* m10C;
    void* m110;
    void* m114;
    void Shutdown();
};

void Obj_0010B680::Shutdown()
{
    if (m10C) {
        func_0010AFE0(this, m114);
        m114 = 0;
        func_0010AFE0(this, m110);
        m110 = 0;
        delete m10C;
        m10C = 0;
    }
}
