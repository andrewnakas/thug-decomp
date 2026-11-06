struct Array_001A27A0 {
    char pad0[0xC];
    unsigned int mC;
    unsigned int GetSize() const { return mC; }
};

extern "C" bool func_001E8248(void* params, unsigned int name, Array_001A27A0** out, int required);
extern "C" void* func_001E9300(Array_001A27A0* a, unsigned int i);

struct Obj_001A27A0 {
    void Fn(void* params);
};

extern "C" void func_001A2A18(Obj_001A27A0* self, void* item);

void Obj_001A27A0::Fn(void* params)
{
    Array_001A27A0* a;
    func_001E8248(params, 0x3ED7262B, &a, 1);
    for (unsigned int i = 0; i < a->GetSize(); i++)
        func_001A2A18(this, func_001E9300(a, i));
}
