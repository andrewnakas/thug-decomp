struct Net_002D87F8 {
    char pad[0xC];
    void* mC;
};
extern Net_002D87F8* D_00392068;
extern "C" int func_002D8210(void* p);

extern "C" bool func_002D87F8() { return func_002D8210(D_00392068->mC) > 0; }
