class Comp_00255C10 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Hide(int hide);
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual bool Dispatch(unsigned int name, void* params, void* script);
};

struct Obj_00255C10 {
    char pad0[0x174];
    int m_ready;
    void Start(int forward);
};

extern "C" Comp_00255C10* func_00185578(void* obj, unsigned int name);
extern "C" void func_001A0AF0(Comp_00255C10* comp, float speed);
extern "C" void func_001A0B50(Comp_00255C10* comp);
extern "C" void func_001A1888(Comp_00255C10* comp, int a);
extern "C" void func_001A0D38(Comp_00255C10* comp);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E72B0(void* s, unsigned int name, float value);
extern "C" void func_001E6AE8(void* s, int flags);

void Obj_00255C10::Start(int forward)
{
    if (func_00185578(this, 0x72AD7B23)) {
        if (forward) {
            func_001A0AF0(func_00185578(this, 0x72AD7B23), 1.0f / 60.0f);
            func_001A0B50(func_00185578(this, 0x72AD7B23));
            void* s = func_001E6978(func_001190D0(8));
            func_001E72B0(s, 0x06C9F278, 1.0f / 60.0f);
            func_00185578(this, 0x72AD7B23)->Dispatch(0x6AAEB76F, s, 0);
            if (s) {
                func_001E6AE8(s, 3);
            }
        } else {
            float speed = -1.0f / 60.0f;
            func_001A1888(func_00185578(this, 0x72AD7B23), 0);
            func_001A0AF0(func_00185578(this, 0x72AD7B23), speed);
            func_001A0B50(func_00185578(this, 0x72AD7B23));
            func_001A1888(func_00185578(this, 0x72AD7B23), 0);
            func_00185578(this, 0x72AD7B23)->Dispatch(0xF5E2B871, 0, 0);
            void* s = func_001E6978(func_001190D0(8));
            func_001E72B0(s, 0x06C9F278, speed);
            func_00185578(this, 0x72AD7B23)->Dispatch(0x6AAEB76F, s, 0);
            if (s) {
                func_001E6AE8(s, 3);
            }
            func_00185578(this, 0x72AD7B23)->Dispatch(0xF5E2B871, 0, 0);
        }
        func_001A0D38(func_00185578(this, 0x72AD7B23));
        func_00185578(this, 0x72AD7B23)->Hide(1);
    }
    m_ready = 1;
}
