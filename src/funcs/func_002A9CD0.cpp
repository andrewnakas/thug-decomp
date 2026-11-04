struct Net_002A9CD0 {
    char pad[0xA4];
    void* mA4;
};
extern Net_002A9CD0* D_00392068;
extern "C" int func_00104968(void* p);

extern "C" int func_002A9CD0() { return func_00104968(D_00392068->mA4); }
