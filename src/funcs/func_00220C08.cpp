struct Obj_00220C08 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual bool CallMember(unsigned int name, void* params, void* script);
};

extern void* D_0038FC78;
extern "C" Obj_00220C08* func_0022DD38(void* self);

bool Cmd_00220C08(void* params, void* script)
{
    return func_0022DD38(D_0038FC78)->CallMember(0x1F8BBD05, params, script);
}
