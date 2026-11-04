struct Obj_002C0E10;
extern "C" int func_002CC318(void* p, int k, int* a);
extern "C" void* func_002CC5A0(void* p, int a, int* b);
extern "C" void func_002C0BE0(Obj_002C0E10* o, void* q);

struct Obj_002C0E10 {
    char pad[0x6B00];
    void* m6B00;
    void Update(int k);
};

void Obj_002C0E10::Update(int k)
{
    int a;
    int b;
    if (func_002CC318(m6B00, k, &a))
        func_002C0BE0(this, func_002CC5A0(m6B00, a, &b));
}
